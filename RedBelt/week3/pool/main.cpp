#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>

template <class T>
class ObjectPool {
public:
    T* Allocate() {
        if (!(*dealoc).empty()){
            auto t = (*dealoc).front();
            (*aloc).insert(t);
            (*dealoc).pop_front();
            return t;
        }
        auto t = new T;
        (*aloc).insert(t);
        return t;
    }
    T* TryAllocate() {
        if ((*dealoc).empty())
            return nullptr;
        auto t = (*dealoc).front();
        (*aloc).insert(t);
        (*dealoc).pop_front();
        return t;
    }

    void Deallocate(T* object) {
        auto value = (*aloc).find(object);
        if (value==(*aloc).end())
            throw std::invalid_argument("invalid_argument");
        (*dealoc).push_back(object);
        (*aloc).erase(value);
    }

    ~ObjectPool() {
        for (auto& t : *aloc){
            delete t;
        }
        for (auto& t : *dealoc){
            delete t;
        }
        delete aloc;
        delete dealoc;
    }

private:
    std::set<T*>* aloc = new std::set<T*>;
    std::deque<T*>* dealoc = new std::deque<T*>;
};

void TestObjectPool() {
    ObjectPool<std::string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}
void Test(){
    ObjectPool<std::string> pool;
    auto p1 = new std::string;
    pool.Deallocate(p1);
    delete p1;
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
