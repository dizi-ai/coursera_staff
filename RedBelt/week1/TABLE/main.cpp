#include "test_runner.h"
#include <utility>
#include <vector>
template <typename T>
class Table{
public:
    Table(const size_t& r, const size_t& c){
        rows=r;
        columns=c;
        Resize(r,c);
    }
    void Resize(const size_t& r, const size_t& c){
        val.resize(r);
        for (auto& it : val)
            it.resize(c);
        rows=r;
        columns=c;
    }
    std::pair<size_t,size_t> Size() const{
        if (rows!=0 && columns!=0)
            return std::make_pair(rows,columns);
        return {0,0};
    }
    std::vector<T>& operator[](const size_t& t ) const{
        return val[t];
    }
    std::vector<T>& operator[](const size_t& t ){
        return val[t];
    }
private:
    size_t rows = 0;
    size_t columns=0;
    std::vector<std::vector<T>> val;

};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}