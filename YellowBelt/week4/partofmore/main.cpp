#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border){
    auto it = std::find_if(elements.begin(),elements.end(),[border](const T& q ){
        return q>border;
    });
    std::vector<T> ret;
    auto n = it;
    for (auto n = it;n != elements.end();n++){
        ret.push_back(*n);
    }
    return ret;
}
int main() {
    for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::string to_find = "Python";
    std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
    return 0;
}