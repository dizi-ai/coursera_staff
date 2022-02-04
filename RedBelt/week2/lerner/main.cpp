#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>

class Learner {
public:
    int Learn(const std::vector<std::string>& words) {
        size_t newWords = dict.size();
        for (const auto& word : words)
            dict.insert(word);
        return dict.size()-newWords;
    }

    std::vector<std::string> KnownWords() {
        return std::vector<std::string>(dict.begin(),dict.end());
    }
private:
    std::set<std::string> dict;

};
int main() {
    Learner learner;
    std::string line;
    while (getline(std::cin, line)) {
        std::vector<std::string> words;
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            words.push_back(word);
        }
        std::cout << learner.Learn(words) << "\n";
    }
    std::cout << "=== known words ===\n";
    for (auto word : learner.KnownWords()) {
        std::cout << word << "\n";
    }
}
