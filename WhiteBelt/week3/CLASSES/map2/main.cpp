#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
std::string FindNameByYear(const std::map<int, std::string>& names, int year) {
    std::string name;
    for (const auto& item : names) {
        if (item.first <= year) {
            name = item.second;

        } else {
            break;
        }
    }
    return name;
}
std::string FindNameByYear2(const std::map<int, std::string>& names, int year, std::vector<std::string>& history) {
    std::string name;
    int it = 0;
    for (const auto& item : names) {
        if (item.first <= year) {
            name = item.second;
            if (it==0) {
                history.push_back(name);
                ++it;
            }
            else if (history[it-1]!=item.second){
                history.push_back(name);
                ++it;
            }
        } else {
            break;
        }
    }
    if (!history.empty())
        history.pop_back();
    std::reverse(history.begin(), history.end());
    return name;
}
class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        last_names[year] = last_name;
    }
    std::string GetFullName(int year) {
        const std::string first_name = FindNameByYear(first_names, year);
        const std::string last_name = FindNameByYear(last_names, year);
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else {
            return first_name + " " + last_name;
        }
    }
    std::string GetFullNameWithHistory(int year) {
        history.clear();
        std::string first_name = FindNameByYear2(first_names, year,history);
        std::string prevnames;
        int it = 0;
        for (auto& c : history){
            if (!c.empty()){
                if (history.size() - 1 - it > 0)
                    prevnames += c + ", ";
                else
                    prevnames += c;
            }
            it++;
        }
        if ((!prevnames.empty())&&(prevnames!=first_name))
            first_name+=" ("+prevnames+")";
        history.clear();
        it = 0;
        prevnames.clear();
        std::string last_name = FindNameByYear2(last_names, year,history);
        for (auto& c : history){
            if (!c.empty()){
                if (history.size() - 1 - it > 0)
                    prevnames += c + ", ";
                else
                    prevnames += c;
            }
            it++;
        }
        if ((!prevnames.empty())&&(prevnames!=last_name))
            last_name+=" ("+prevnames+")";
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else {
            return first_name + " " + last_name;
        }
    }
private:
    std::vector<std::string> history;
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
};
int main() {
    Person person;

   /* person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    std::cout << person.GetFullNameWithHistory(1990) << std::endl;

    person.ChangeFirstName(1966, "Pauline");
    std::cout << person.GetFullNameWithHistory(1966) << std::endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    std::cout << person.GetFullNameWithHistory(1967) << std::endl;
*/
    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    std::cout << person.GetFullNameWithHistory(1940) << std::endl;

    return 0;
}
