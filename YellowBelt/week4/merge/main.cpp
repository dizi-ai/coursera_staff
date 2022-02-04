#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

template<typename T>
void MergeSort(T f, T s) {
    int len = s-f;
    if (len<3) {
        return;
    }
    std::vector<typename T::value_type> elements(f, s);
    auto r = elements.begin()+ len/3;
    MergeSort(elements.begin(),r);
    auto r1 = r+ len/3;
    MergeSort(r,r1);
    MergeSort(r1,elements.end());
    std::vector<typename T::value_type> temp;
    std::merge(elements.begin(),r ,r ,r1,std::back_inserter(temp));
    std::merge(temp.begin(),temp.end() ,r1 ,elements.end(),f);
}
int main() {
    std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
