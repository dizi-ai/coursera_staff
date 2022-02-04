#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <tuple>
/*
enum class Lang {
    DE, FR, IT
};
struct Region {
    std::string std_name;
    std::string parent_std_name;
    std::map<Lang, std::string> names;
    int64_t population;
};
 */
bool operator<(const Region& f, const Region& s) {
    return std::tie(f.std_name, f.parent_std_name, f.population,f.names)<std::tie(s.std_name, s.parent_std_name, s.population,s.names);

}
int FindMaxRepetitionCount(const std::vector<Region>& regions) {
    int res=0;
    std::map<Region, int > rep;
    for (const auto& c : regions)
        res = std::max(res, ++rep[c]);
    return res;

}
/*
int main()
{
    std::cout << FindMaxRepetitionCount({
        {
                "Moscow",
                "Russia",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"},{Lang::IT, "Mosca"}},
                89
        },{
                "Russia",
                "Eurasia",
                {{Lang::DE, "Russland"}, {Lang::FR, "Russie"},{Lang::IT, "Russia"}},
                89
        },{
                "Moscow",
                "Russia",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"},{Lang::IT, "Mosca"}},
                89
        },{
                "Moscow",
                "Russia",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"},{Lang::IT, "Mosca"}},
                89
        },{
                "Russia",
                "Eurasia",
                {{Lang::DE, "Russland"}, {Lang::FR, "Russie"},{Lang::IT, "Russia"}},
                89
        }
    }) << std::endl;
    //std::cout << FindMaxRepetitionCount() << std::endl;
}
*/

