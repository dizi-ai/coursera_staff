#pragma once
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>

class Date{
public:
    Date(int new_year, int new_month, int new_day);
    [[nodiscard]] int GetYear() const ;
    [[nodiscard]] int GetMonth() const ;
    [[nodiscard]] int GetDay() const ;
private:
    int year;
    int day;
    int month;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date &lhs, const Date &rhs);
bool operator==(const Date &lhs, const Date &rhs);
bool operator!=(const Date &lhs, const Date &rhs);
bool operator>(const Date &lhs, const Date &rhs);
bool operator>=(const Date &lhs, const Date &rhs);

std::ostream& operator<<(std::ostream& stream, const Date& date);

Date ParseDate(std::istream& is);