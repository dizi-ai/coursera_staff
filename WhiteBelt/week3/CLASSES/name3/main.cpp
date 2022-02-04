#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> FindNamesHistory(const std::map<int, std::string>& names_by_year,
                                int year) {
    std::vector<std::string> names;
    for (const auto& item : names_by_year) {
        if (item.first <= year && (names.empty() || names.back() != item.second)) {
            names.push_back(item.second);
        }
    }
    return names;
}

std::string BuildJoinedName(std::vector<std::string> names) {
    if (names.empty()) {
        return "";
    }
    reverse(begin(names), end(names));
    std::string joined_name = names[0];
    for (int i = 1; i < names.size(); ++i) {
        if (i == 1) {
            joined_name += " (";
        } else {
            joined_name += ", ";
        }
        joined_name += names[i];
    }
    if (names.size() > 1) {
        joined_name += ")";
    }
    return joined_name;
}
std::string BuildFullName(const std::string& first_name, const std::string& last_name)  {
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

class Person {
public:
    Person(const std::string& n, const std::string& s, const int date){
        name = n;
        surname=s;
        birth=date;
        ChangeFirstName(birth, name);
        ChangeLastName(birth,surname);
    }
    void ChangeFirstName(int year, const std::string& first_name) {
        if (year>=birth)
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        if (year>=birth)
        last_names[year] = last_name;
    }

    [[nodiscard]] std::string GetFullName(int year) const{
        if (year>=birth) {
            const std::vector<std::string> first_names_history = FindFirstNamesHistory(year);
            const std::vector<std::string> last_names_history = FindLastNamesHistory(year);
            std::string first_name;
            std::string last_name;
            if (!first_names_history.empty()) {
                first_name = first_names_history.back();
            }
            if (!last_names_history.empty()) {
                last_name = last_names_history.back();
            }
            return BuildFullName(first_name, last_name);
        }
        else {
            return "No person";
        }
    }

    [[nodiscard]] std::string GetFullNameWithHistory(int year) const{
        if (year>=birth) {
        const std::string first_name = BuildJoinedName(FindFirstNamesHistory(year));
        const std::string last_name = BuildJoinedName(FindLastNamesHistory(year));
        return BuildFullName(first_name, last_name);
        }
        else {
            return "No person";
        }
    }

private:
    std::string name;
    std::string surname;
    int birth;
    [[nodiscard]] std::vector<std::string> FindFirstNamesHistory(int year) const{
        return FindNamesHistory(first_names, year);
    }
    [[nodiscard]] std::vector<std::string> FindLastNamesHistory(int year) const{
        return FindNamesHistory(last_names, year);
    }

    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
};
int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
       std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }
    return 0;
}