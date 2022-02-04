#include "test_runner.h"
#include <numeric>
#include <vector>
#include <string>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
template <typename T>
class Synchronized {
public:
    explicit Synchronized(T initial = T()){
        value=std::move(initial);
    }

    struct Access {
        T& ref_to_value;
        std::lock_guard<std::mutex> lg;
    };
    Access GetAccess() {
        return{value,std::lock_guard(m)};
    }
private:
    std::mutex m;
    T value;
};

void TestConcurrentUpdate() {
    Synchronized<std::string> common_string;

    const size_t add_count = 50000;
    auto updater = [&common_string, add_count] {
        for (size_t i = 0; i < add_count; ++i) {
            auto access = common_string.GetAccess();
            access.ref_to_value += 'a';
        }
    };

    auto f1 = std::async(updater);
    auto f2 = std::async(updater);

    f1.get();
    f2.get();

    ASSERT_EQUAL(common_string.GetAccess().ref_to_value.size(), 2 * add_count);
}

std::vector<int> Consume(Synchronized<std::deque<int>>& common_queue) {
    std::vector<int> got;

    for (;;) {
        std::deque<int> q;

        {
        // Мы специально заключили эти две строчки в операторные скобки, чтобы
        // уменьшить размер критической секции. Поток-потребитель захватывает
        // мьютекс, перемещает всё содержимое общей очереди в свою
        // локальную переменную и отпускает мьютекс. После этого он обрабатывает
        // объекты в очереди за пределами критической секции, позволяя
        // потоку-производителю параллельно помещать в очередь новые объекты.
        //
        // Размер критической секции существенно влияет на быстродействие
        // многопоточных программ.
        auto access = common_queue.GetAccess();
        q = move(access.ref_to_value);
        }

        for (int item : q) {
            if (item > 0) {
                got.push_back(item);
            }
            else {
                return got;
            }
        }
    }
}

void TestProducerConsumer() {
    Synchronized<std::deque<int>> common_queue;

    auto consumer = async(Consume, ref(common_queue));

    const size_t item_count = 100000;
    for (size_t i = 1; i <= item_count; ++i) {
        common_queue.GetAccess().ref_to_value.push_back(i);
    }
    common_queue.GetAccess().ref_to_value.push_back(-1);

    std::vector<int> expected(item_count);
    iota(begin(expected), end(expected), 1);
    ASSERT_EQUAL(consumer.get(), expected);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestConcurrentUpdate);
    RUN_TEST(tr, TestProducerConsumer);
}
