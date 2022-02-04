#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <deque>

template <typename T>
class PriorityCollection {
public:
    using Id = int;
    // Добавить объект с нулевым приоритетом
    // с помощью перемещения и вернуть его идентификатор
    Id Add(T object) {
        const Id id = data.size();
        data.push_back({std::move(object)});
        sorted.insert({0,id});
        return id;
    }

    // Добавить все элементы диапазона [range_begin, range_end)
    // с помощью перемещения, записав выданные им идентификаторы
    // в диапазон [ids_begin, ...)
    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt range_begin, ObjInputIt range_end,IdOutputIt ids_begin) {
        while (range_begin!=range_end) {
            *ids_begin++=Add(std::move(*range_begin++));
        }
    }

    // Определить, принадлежит ли идентификатор какому-либо
    // хранящемуся в контейнере объекту
    bool IsValid(Id id) const {
        if (id>=0 && id < data.size() &&  data[id].priority>=0)
            return true;
        return false;
    }

    // Получить объект по идентификатору
    const T& Get(Id id) const {
        return data[id].data;
    }

    // Увеличить приоритет объекта на 1
    void Promote(Id id) {
        auto& toret = data[id];
        Id op = toret.priority;
        Id np = op+1;
        sorted.erase({op,id});
        sorted.insert({np,id});
        data[id].priority++;
    }

    // Получить объект с максимальным приоритетом и его приоритет
    std::pair<const T&, int> GetMax() const {
        const std::pair<const T&, int>& toret={data[std::prev(sorted.end())->second].data,data[std::prev(sorted.end())->second].priority};
        return toret;
    }

    // Аналогично GetMax, но удаляет элемент из контейнера
    std::pair<T, int> PopMax() {
        //auto it =std::move(data.end());
        auto& toret=data[std::prev(sorted.end())->second];
        int prior=toret.priority;
        sorted.erase(std::prev(sorted.end()));
        toret.priority=NONE_PRIORITY;
        return {std::move(toret.data),prior};
    }


private:
    struct ObjectItem
    {
        T data;
        int priority = 0;
    };
    static const int NONE_PRIORITY = -1;

    std::vector<ObjectItem> data;
    std::set<std::pair<int, Id>> sorted;
    // Приватные поля и методы
};


class StringNonCopyable : public std::string {
public:
    using std::string::string;  // Позволяет использовать конструкторы строки
    StringNonCopyable(const StringNonCopyable&) = delete;
    StringNonCopyable(StringNonCopyable&&) = default;
    StringNonCopyable& operator=(const StringNonCopyable&) = delete;
    StringNonCopyable& operator=(StringNonCopyable&&) = default;
};
void TestNoCopy() {
    PriorityCollection<StringNonCopyable> strings;
    const auto white_id = strings.Add("white");
    const auto yellow_id = strings.Add("yellow");
    const auto red_id = strings.Add("red");

    strings.Promote(yellow_id);
    for (int i = 0; i < 2; ++i) {
        strings.Promote(red_id);
    }
    strings.Promote(yellow_id);
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "red");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "yellow");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "white");
        ASSERT_EQUAL(item.second, 0);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestNoCopy);
    return 0;
}
