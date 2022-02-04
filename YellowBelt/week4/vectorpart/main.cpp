#include <iostream>
#include <vector>
#include <algorithm>
void PrintVectorPart(const std::vector<int>& numbers) {
    auto res = std::find_if(numbers.begin(),numbers.end(),
                [](int num){
        return num<0;
    });
    for (auto it = res; it >numbers.begin();){
        std::cout << *(--it)<<" ";
    }
}
int main() {
    PrintVectorPart({6, 1, 8, -5, 4});
    std::cout << std::endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    std::cout << std::endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    std::cout << std::endl;
    return 0;
}