#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <iterator>
#include "timer.h"

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2)
    {
        return;
    }

    std::vector<typename RandomIt::value_type> tmp_vec(std::make_move_iterator(range_begin),
                                                       std::make_move_iterator(range_end));

    const int left_border = (tmp_vec.end() - tmp_vec.begin()) / 3;
    const int right_border = left_border * 2;

    MergeSort(std::move(tmp_vec.begin()), std::move(tmp_vec.begin() + left_border));
    MergeSort(std::move(tmp_vec.begin() + left_border), std::move(tmp_vec.begin() + right_border));
    MergeSort(std::move(tmp_vec.begin() + right_border), std::move(tmp_vec.end()));

    std::vector<typename RandomIt::value_type> also_tmp_vec;

    std::merge(std::make_move_iterator(tmp_vec.begin()),
               std::make_move_iterator(tmp_vec.begin() + left_border),
               std::make_move_iterator(tmp_vec.begin() + left_border),
               std::make_move_iterator(tmp_vec.begin() + right_border),
               std::back_inserter(also_tmp_vec));

    std::merge(std::make_move_iterator(also_tmp_vec.begin()),
               std::make_move_iterator(also_tmp_vec.end()),
               std::make_move_iterator(tmp_vec.begin() + right_border),
               std::make_move_iterator(tmp_vec.end()),
               range_begin);
    /*
    if (std::distance(range_begin,range_end)<2)
        return;
    std::vector<typename RandomIt::value_type> elements(std::make_move_iterator(range_begin), std::make_move_iterator(range_end));
    const int r =std::distance(elements.begin(),elements.end())/3;
    const int r1 = r*2;
    MergeSort(std::move(elements.begin()),std::move(elements.begin()+r));
    MergeSort(std::move(elements.begin()+r),std::move(elements.begin()+r1));
    MergeSort(std::move(elements.begin()+r1),std::move(elements.end()));
    std::vector<typename RandomIt::value_type> temp;
    std::merge(std::make_move_iterator(elements.begin()),
               std::make_move_iterator(elements.begin()+r),
               std::make_move_iterator(elements.begin()+r),
               std::make_move_iterator(elements.begin()+r1),
               std::back_inserter(temp));
    std::merge(std::make_move_iterator(temp.begin()),
               std::make_move_iterator(temp.end()),
               std::make_move_iterator(elements.begin()+r1),
               std::make_move_iterator(elements.end()),
               range_end);
    */
}

void TestIntVector() {
    vector<int> numbers(100002);
    vector<int> numbers1(100002);
    for (int i =100002;i>0;--i){
        numbers.push_back(i);
        numbers1.push_back(i);
    };
    { Timer("merge")
        MergeSort(begin(numbers), end(numbers));
        ASSERT(is_sorted(begin(numbers), end(numbers)));
    }

    { Timer("sort")
        std::sort(numbers1.begin(),numbers1.end());
        ASSERT(is_sorted(begin(numbers1), end(numbers1)));
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestIntVector);
    return 0;
}
