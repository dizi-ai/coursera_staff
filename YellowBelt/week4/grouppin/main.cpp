
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, std::string prefix) {

    auto it = std::lower_bound(range_begin, range_end, prefix);
    auto it1 = std::upper_bound(range_begin, range_end, ++prefix[prefix.size()-1]);
    return std::make_pair(it, it1);
}

int main() {
    const std::vector<std::string> sorted_strings = { "moscow", "motovilikha", "murmansk" };
    const auto a_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    std::cout << (a_result.first - begin(sorted_strings)) << " " <<
              (a_result.second - begin(sorted_strings)) << std::endl;

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    std::cout << (m_result.first - begin(sorted_strings)) << " " <<
              (m_result.second - begin(sorted_strings)) << std::endl;
    std::cout << std::endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    std::cout << (p_result.first - begin(sorted_strings)) << " " <<
              (p_result.second - begin(sorted_strings)) << std::endl;


    return 0;
}