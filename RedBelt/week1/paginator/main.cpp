#include "test_runner.h"

#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
// Реализуйте шаблон класса Paginator
template <typename Iterator>
class Page{
public:
    Page(const Iterator& f,const Iterator& s):first(f),second(s){}
    auto begin() const{
        return first;
    }
    auto end() const{
        return second;
    }
    size_t size() const{
        return std::distance(first,second);
    }
private:
    Iterator first;
    Iterator second;

};
template <typename Iterator>
class Paginator {
public:
    Paginator(const Iterator& f, const Iterator& s,const size_t& ps){
        for (auto i = 0; i <std::distance(f,s); i+=ps) {
            if (i + ps < distance(f, s))
                v.push_back(Page(f + i, f + i + ps));
            else
                v.push_back(Page(f + i, s));
        }
    }
    auto begin() const{
        return v.begin();
    }
    auto end() const{
        return v.end();
    }
    size_t size() const{
        return v.size();
    }
private:
    std::vector<Page<Iterator>> v;
};

template <typename Cont>
auto Paginate(Cont& c, const size_t& page_size) {
    return Paginator(c.begin(),c.end(),page_size);
}

void TestPageCounts() {
    std::vector<int> v(15);
    ASSERT_EQUAL(Paginate(v, 1).size(), v.size());
    std::cout<<"yeah"<<std::endl;
    ASSERT_EQUAL(Paginate(v, 3).size(), 5u);
    std::cout<<"yeah"<<std::endl;
    ASSERT_EQUAL(Paginate(v, 5).size(), 3u);
    std::cout<<"yeah"<<std::endl;
    ASSERT_EQUAL(Paginate(v, 4).size(), 4u);
    std::cout<<"yeah"<<std::endl;
    ASSERT_EQUAL(Paginate(v, 15).size(), 1u);
    std::cout<<"yeah"<<std::endl;
    ASSERT_EQUAL(Paginate(v, 150).size(), 1u);
    std::cout<<"yeah"<<std::endl;
    ASSERT_EQUAL(Paginate(v, 14).size(), 2u);
    std::cout<<"yeah"<<std::endl;

}
void TestLooping() {
    std::vector<int> v(15);
    std::iota(begin(v), end(v), 1);

    Paginator<vector<int>::iterator> paginate_v(v.begin(), v.end(), 6);
    std::ostringstream os;
    for (const auto& page : paginate_v) {
        for (int x : page) {
            os << x << ' ';
        }
        os << '\n';
    }

    ASSERT_EQUAL(os.str(), "1 2 3 4 5 6 \n7 8 9 10 11 12 \n13 14 15 \n");
}
void TestModification() {
    std::vector<string> vs = {"one", "two", "three", "four", "five"};
    for (auto page : Paginate(vs, 2)) {
        for (auto& word : page) {
            word[0] = toupper(word[0]);
        }
    }

    const std::vector<std::string> expected = {"One", "Two", "Three", "Four", "Five"};
    ASSERT_EQUAL(vs, expected);
}
void TestPageSizes() {
    std::string letters(26, ' ');

    Paginator letters_pagination(letters.begin(), letters.end(), 11);
    std::vector<size_t> page_sizes;
    for (const auto& page : letters_pagination) {
        page_sizes.push_back(page.size());
    }

    const vector<size_t> expected = {11, 11, 4};
    ASSERT_EQUAL(page_sizes, expected);
}

void TestConstContainer() {
    const string letters = "abcdefghijklmnopqrstuvwxyz";

    vector<string> pages;
    for (const auto& page : Paginate(letters, 10)) {
        pages.push_back(string(page.begin(), page.end()));
    }

    const vector<string> expected = {"abcdefghij", "klmnopqrst", "uvwxyz"};
    ASSERT_EQUAL(pages, expected);
}

void TestPagePagination() {
    vector<int> v(22);
    iota(begin(v), end(v), 1);

    vector<vector<int>> lines;
    for (const auto& split_by_9 : Paginate(v, 9)) {
        for (const auto& split_by_4 : Paginate(split_by_9, 4)) {
            lines.push_back({});
            for (int item : split_by_4) {
                lines.back().push_back(item);
            }
        }
    }

    const vector<vector<int>> expected = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9},
            {10, 11, 12, 13},
            {14, 15, 16, 17},
            {18},
            {19, 20, 21, 22}
    };
    ASSERT_EQUAL(lines, expected);
}
int main() {
    /*
    TestRunner tr;
    RUN_TEST(tr, TestPageCounts);
    RUN_TEST(tr, TestLooping);
    RUN_TEST(tr, TestModification);
    RUN_TEST(tr, TestPageSizes);
    RUN_TEST(tr, TestConstContainer);
    RUN_TEST(tr, TestPagePagination);*/
}
