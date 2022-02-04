#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> PalindromFilter(std::vector<std::string> words,  int minLength) {
    bool sum = 0;
    std::vector<std::string> backup;
    for (std::string x : words) {
        if (x.size()>=minLength) {
            int j = x.size() - 1;
            for (int i = 0; i <= j; i++) {
                //std::cout << "i " <<x[i] <<" j "<<x[j] << std::endl;
                if (x[i] == x[j]) {

                    sum = true;
                } else {
                    sum = false;
                    break;
                }
                j--;
            }
        }
        if (sum)
         backup.push_back(x);
        sum = false;

    }
     return backup;
}

int main() {
    std::vector<std::string> words={"abacaba","aba"};
    for(std::string c :PalindromFilter(words,5))
        std::cout<<c<<" ";
}
