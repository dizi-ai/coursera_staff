#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;
std::istream& operator>>(std::istream&is ,Date& lhs){
    std::string temp;
    is >> temp;
    for (auto& t : temp)
        if (t=='-')
            t=' ';
    std::istringstream str(temp);
    str>>lhs.year>>lhs.month>>lhs.day;
    return is;
}
std::istream& operator>>(std::istream&is ,Time& lhs){
    std::string temp;
    is >> temp;
    for (auto& t : temp)
        if (t==':')
            t=' ';
    std::istringstream str(temp);
    str>>lhs.hours>>lhs.minutes;
    return is;
}
std::ostream& operator<<(std::ostream&os ,const Date& lhs){
    return os;
}
std::ostream& operator<<(std::ostream&os ,const Time& lhs){
    return os;
}
bool operator< (const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.year,lhs.month,lhs.day)<std::make_tuple(rhs.year,rhs.month,rhs.day);
}
bool operator== (const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.year,lhs.month,lhs.day)==std::make_tuple(rhs.year,rhs.month,rhs.day);
}
bool operator< (const Time& lhs, const Time& rhs){
    return std::make_tuple(lhs.hours,lhs.minutes)<std::make_tuple(rhs.hours,rhs.minutes);
}
bool operator== (const Time& lhs, const Time& rhs){
    return std::make_tuple(lhs.hours,lhs.minutes)==std::make_tuple(rhs.hours,rhs.minutes);
}
#define UPDATE_FIELD(ticket, field, values) \
if (values.find(#field) != values.end()) {    \
istringstream is(values.find(#field)->second);\
is >> ticket.field;                           \
}\

  // Реализуйте этот макрос, а также необходимые операторы для классов Date и Time

void TestUpdate() {
    AirlineTicket t;
    t.price = 0;

    const map<string, string> updates1 = {
            {"departure_date", "2018-2-28"},
            {"departure_time", "17:40"},
    };
    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);

    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 0);

    const map<string, string> updates2 = {
            {"price", "12550"},
            {"arrival_time", "20:33"},
    };
    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);

    // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
    // значения этих полей не должны измениться
    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
}
