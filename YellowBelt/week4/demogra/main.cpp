#include <iostream>
#include <vector>
#include <algorithm>
/*
enum class Gender {
    FEMALE,
    MALE
};
struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};
 */
void PrintStats(vector<Person> persons) {
    // Преобразуем порядок людей к следующему:
    //                  persons
    //                 /      \
    //          females        males
    //         /       \     /      \
    //      empl.  unempl. empl.   unempl.
    auto females_end = partition(
            begin(persons), end(persons), [](const Person& p) {
                return p.gender == Gender::FEMALE;
            }
    );
    auto employed_females_end = partition(
            begin(persons), females_end, [](const Person& p) {
                return p.is_employed;
            }
    );
    auto employed_males_end = partition(
            females_end, end(persons), [](const Person& p) {
                return p.is_employed;
            }
    );

    // Теперь интересующие нас группы находятся в векторе непрерывно
    std::cout << "Median age = "
         << ComputeMedianAge(begin(persons), end(persons))          << std::endl;
    std::cout << "Median age for females = "
         << ComputeMedianAge(begin(persons), females_end)           << std::endl;
    std::cout << "Median age for males = "
         << ComputeMedianAge(females_end, end(persons))             << std::endl;
    std::cout << "Median age for employed females = "
         << ComputeMedianAge(begin(persons),  employed_females_end) << std::endl;
    std::cout << "Median age for unemployed females = "
         << ComputeMedianAge(employed_females_end, females_end)     << std::endl;
    std::cout << "Median age for employed males = "
         << ComputeMedianAge(females_end, employed_males_end)       << std::endl;
    std::cout << "Median age for unemployed males = "
         << ComputeMedianAge(employed_males_end, end(persons))      << std::endl;
}
/*
int main() {
    std::vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}
*/