#include "date.h"
#include <tuple>


std::ostream& operator<<(std::ostream& stream, const Date& date) {
    stream << std::setw(4) << std::setfill('0') << date.GetYear() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetMonth() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetDay();
    return stream;
}

Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw std::logic_error("Month value is invalid: " + std::to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw std::logic_error("Day value is invalid: " + std::to_string(new_day));
    }
    day = new_day;
}
int Date::GetYear() const {
    return year;
}
int Date::GetMonth() const {
    return month;
}
int Date::GetDay() const {
    return day;
}
Date ParseDate(std::istream& is) {
    int year, month, day;

    is >> year;
    is.ignore(1);

    is >> month;
    is.ignore(1);

    is >> day;

    return Date(year, month, day);
}
bool operator<(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay())<std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}
bool operator>(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay())>std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}
bool operator>=(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay())>=std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}
bool operator<=(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay())<=std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}
bool operator==(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay())==std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}
bool operator!=(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay())!=std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}