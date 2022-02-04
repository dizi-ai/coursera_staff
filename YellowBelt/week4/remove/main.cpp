#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
void RemoveDuplicates(std::vector<T>& elements) {
    std::sort(elements.begin(), elements.end());
    auto last = std::unique(elements.begin(), elements.end());
    elements.erase(last, elements.end());
}

int main() {
    std::vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
    RemoveDuplicates(v1);
    for (int x : v1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> v2 = { "C", "C++", "C++", "C", "C++" };
    RemoveDuplicates(v2);
    for (const std::string& s : v2) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::vector<double> v3 = { 1.01, 1.01, 1.01, 0.3, 1.01 };
    RemoveDuplicates(v3);
    for (const double& s : v3) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::vector<double> v4 = { 1.01, 1.01, 1.01, 1.01, 1.01 };
    RemoveDuplicates(v4);
    for (const double& s : v4) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}
