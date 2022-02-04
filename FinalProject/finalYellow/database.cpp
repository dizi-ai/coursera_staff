#include "database.h"

std::ostream &operator<<(std::ostream &os, const Entry &entry) {
    os << entry.date << " " << entry.event;
    return os;
}

void Database::Add(const Date &date, const std::string &event) {
    if (storage.count(date)) {
        auto insert_result = storage[date].first.insert(event);
        if (insert_result.second) {
            storage[date].second.push_back(insert_result.first);
        }
    } else {

        auto insert_result  = storage[date].first.insert(event);
        storage[date].second.push_back(insert_result.first);
    }
}

void Database::Print(std::ostream &os) const {
    for (auto date_it = storage.begin(); date_it != storage.end(); date_it = std::next(date_it)) {
        for(auto event_it : (*date_it).second.second) {
            os << (*date_it).first << " " << *event_it << "\n";
        }
    }
}

std::string PD(const Date& date){
    std::string ret1 = std::to_string(date.GetYear());
    ret1.insert(ret1.begin(),4-ret1.size(),'0');
    std::string ret2=std::to_string(date.GetMonth());
    ret2.insert(ret2.begin(),2-ret2.size(),'0');
    std::string ret3=std::to_string(date.GetDay());
    ret3.insert(ret3.begin(),2-ret3.size(),'0');
    return (ret1+"-"+ret2+"-"+ret3);
}

std::string Database::Last(const Date &date) const {
    auto it = storage.upper_bound(date);
    if (it != storage.begin()) {
        return (PD(std::prev(it)->first) + " " + (*(*std::prev(it)).second.second.back()));
    } else {
        return "No entries";
    }
}