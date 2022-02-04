#include "test_runner.h"
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class ReadingManager {
public:
    ReadingManager(): current_pages(MAX_USER_COUNT_ + 1, -1), pages(MAX_PAGES_COUNT_+1,0) {}

    void Read(int user_id, int page_count) {
        if (current_pages[user_id]!=-1) {
            pages[current_pages[user_id]]--;
            how_much--;
        }
        pages[page_count]++;
        current_pages[user_id]=page_count;
        how_much++;
        last=0;
        while (true){
            if(pages[last]!=0){
                break;
            }
            last++;
        }
    }

    double Cheer(int user_id) const {
        if (how_much==0||current_pages[user_id]==-1)
            return 0;
        if (how_much==1)
            return 1;
        if (how_much==pages[current_pages[user_id]])
            return 1;
        if (current_pages[user_id]==last)
            return 0;
        int helper = 0;
        for (int i = 1; i <current_pages[user_id];++i){
            helper+=pages[i];
        }
        return helper*1.0/(how_much-1);
    }
private:
    int how_much=0;
    int last=0;
    static const int MAX_USER_COUNT_ = 100'000;
    static const int MAX_PAGES_COUNT_ = 1000;
    vector<int> current_pages;
    vector<int> pages;

};
void Test1(){
    ReadingManager manager;
    ASSERT_EQUAL(manager.Cheer(5),0)
    manager.Read(1, 10);
    ASSERT_EQUAL(manager.Cheer(1),1)
    manager.Read(2, 5);
    manager.Read(3, 7);
    ASSERT_EQUAL(manager.Cheer(2),0)
    ASSERT_EQUAL(manager.Cheer(3),0.5)
    manager.Read(3, 10);
    ASSERT_EQUAL(manager.Cheer(3),0.5)
    manager.Read(3, 11);
    ASSERT_EQUAL(manager.Cheer(3),1)
    ASSERT_EQUAL(manager.Cheer(1),0.5)
}
void Test2(){
    ReadingManager manager;
    manager.Read(1, 10);
    manager.Read(2, 10);
    manager.Read(3, 10);
    ASSERT_EQUAL(manager.Cheer(1),1)
}
void Test3(){
    ReadingManager manager;
    manager.Read(1, 1);
    manager.Read(2, 1);
    manager.Read(3, 1);
    ASSERT_EQUAL(manager.Cheer(1),1)
    ASSERT_EQUAL(manager.Cheer(2),1)
    ASSERT_EQUAL(manager.Cheer(3),1)
}
void Test4(){
    ReadingManager manager;
    manager.Read(1, 1);
    manager.Read(2, 2);
    manager.Read(3, 3);
    ASSERT_EQUAL(manager.Cheer(2), 0.5)
    manager.Read(4, 4);
    ASSERT_EQUAL(manager.Cheer(2), 1.0 / 3.0)
}
void TestRead() {
    ReadingManager manager;

    ASSERT_EQUAL(0, manager.Cheer(5))
    manager.Read(1, 10);
    ASSERT_EQUAL(1, manager.Cheer(1))
    manager.Read(2, 5);
    manager.Read(3, 7);
    ASSERT_EQUAL(0, manager.Cheer(2))
    ASSERT_EQUAL(0.5, manager.Cheer(3))
    manager.Read(3, 10);
    ASSERT_EQUAL(0.5, manager.Cheer(3))
    manager.Read(3, 11);
    ASSERT_EQUAL(1, manager.Cheer(3))
    ASSERT_EQUAL(0.5, manager.Cheer(1))
    manager.Read(2, 11);
    ASSERT_EQUAL(0.5, manager.Cheer(3))
    ASSERT_EQUAL(0.5, manager.Cheer(2))
    manager.Read(2, 12);
    ASSERT_EQUAL(0.5, manager.Cheer(3))
    ASSERT_EQUAL(1, manager.Cheer(2))
    manager.Read(1, 13);
    manager.Read(2, 13);
    manager.Read(3, 13);
    ASSERT_EQUAL(0, manager.Cheer(1))
    ASSERT_EQUAL(0, manager.Cheer(2))
    ASSERT_EQUAL(0, manager.Cheer(3))
}
void Run(){
    TestRunner tr;
    RUN_TEST(tr, Test1);
    RUN_TEST(tr, Test2);
    RUN_TEST(tr, Test3);
    RUN_TEST(tr, Test4);
    RUN_TEST(tr, TestRead);
}
int main() {
    Run();
    /*
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }
*/
    return 0;
}