#include <iostream>
#include <algorithm>
#include "sum_reverse_sort.h"

int Sum(int x, int y) {
    return x + y;
}

std::string Reverse(std::string s) {
    std::string tmp = "";
    for (size_t k = s.length(); k > 0; --k) {
        size_t i = k - 1;
        tmp += s[i];
    }
    return tmp;
}

void Sort( std::vector<int> & nums) {
    sort(begin(nums), end(nums));
}
/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
