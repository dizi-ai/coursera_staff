#pragma once
#include "date.h"

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <utility>
#include <set>

using namespace std;


struct Entry {
    Date date;
    std::string event;
};

std::ostream& operator<<(std::ostream& os, const Entry& entry);

class Database {
public:
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& os) const;

    template<typename L>
    int RemoveIf(const L predicate) {
        int count = 0;
        for(auto date_it = storage.begin(); date_it != storage.end();) {
            for(auto event_it = (*date_it).second.second.begin(); event_it != (*date_it).second.second.end();) {
                if(predicate((*date_it).first, *(*event_it))) {
                    storage[(*date_it).first].first.erase(*(*event_it));
                    event_it = storage[(*date_it).first].second.erase(event_it);
                    ++count;
                } else {
                    event_it = next(event_it);
                }
            }
            if((*date_it).second.first.empty()) {
                date_it = storage.erase(date_it);
            } else {
                date_it = next(date_it);
            }
        }
        return count;
    }

    template<typename L>
    std::vector<Entry> FindIf(const L predicate) const {
        std::vector<Entry> output;
        for(auto date_it = storage.begin(); date_it != storage.end(); date_it = std::next(date_it)) {
            for(auto event_it = (*date_it).second.second.begin(); event_it != (*date_it).second.second.end(); event_it = next(event_it)) {
                if(predicate((*date_it).first, *(*event_it))) {
                    output.push_back({(*date_it).first, *(*event_it)});
                }
            }
        }
        return output;
    }


    [[nodiscard]] std::string Last(const Date& date) const;

private:
    std::map<Date, std::pair<std::set<string>, std::vector<std::set<string>::iterator>>> storage;
};