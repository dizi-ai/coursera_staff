#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    std::string bus;
    std::string stop;
    std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q) {
    q.stops.clear();
    std::string std;
    std::cin>>std;
    q.type = std == "NEW_BUS" ? QueryType::NewBus : std == "BUSES_FOR_STOP" ? QueryType::BusesForStop : std == "STOPS_FOR_BUS" ? QueryType::StopsForBus : std == "ALL_BUSES" ? QueryType::AllBuses:throw std::runtime_error("INCORRECT INPUT");
    if (q.type == QueryType::NewBus) {
        std::cin >> q.bus;
        int stop_count;
        std::cin >> stop_count;
        for (int i = 0; i < stop_count; ++i) {
            std::cin >> q.stop;
            q.stops.push_back(q.stop);
        }
    }
    else if (q.type == QueryType::BusesForStop) {
        std::cin >> q.stop;
    }
    else if (q.type == QueryType::StopsForBus) {
        std::cin >> q.bus;
    }
    return is;
}

struct BusesForStopResponse {
    std::vector<std::string> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
    if (r.buses.empty()) {
        os << "No stop";
    }
    else {
        for (const auto& item : r.buses)
            os << item << " ";
    }
    return os;
}

struct StopsForBusResponse {
    std::vector<std::pair<std::string, std::vector<std::string>>> stops;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
    bool first = true;
    if (r.stops.empty()) {
        os << "No bus";
    }
    else {

        for (const auto& item : r.stops) {
            if (!first)
                os << std::endl;
            first= false;
            os << "Stop " << item.first << ":";
            if (item.second.empty()) {
                os << " no interchange";
            }
            else {
                for (const auto& c : item.second) {
                    os << " " << c;
                }
            }
        }
    }
    return os;
}

struct AllBusesResponse {
    std::map <std::string, std::vector<std::string>> buses;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
    if (r.buses.empty()) {
        os << "No buses";
    }
    else {
        for (const auto& item : r.buses) {
            os <<"Bus " <<item.first << ":";
            for (const auto& c : item.second) {
                os << " " << c;
            }
            os << std::endl;
        }
    }
    return os;
}

class BusManager {
public:
    void AddBus(const std::string& bus, const std::vector<std::string>& stops) {
        all_buses.buses[bus] = stops;
        for (const auto& c : stops)
            bfsr[c].buses.push_back(bus);
    }

    BusesForStopResponse GetBusesForStop(const std::string& stop) const {
        try {
            return bfsr.at(stop);
        }
        catch (...) {
            return {};
        }
    }

    StopsForBusResponse GetStopsForBus(const std::string& bus) const {
        try {
            StopsForBusResponse sfbr;
            for (auto& item : all_buses.buses.at(bus)) {
                std::vector<std::string> temp;
                for (auto& item2 : bfsr.at(item).buses){
                    if (item2 != bus) {
                        temp.push_back(item2);
                    }
                }
                sfbr.stops.push_back(std::make_pair(item, temp));
            }
            return sfbr;
        }
        catch (...) {
            return {};
        }
    }

    AllBusesResponse GetAllBuses() const {

        return all_buses;
    }
private:
    AllBusesResponse all_buses;
    std::map<std::string, BusesForStopResponse> bfsr;
};

int main() {
    int query_count;
    Query q;

    std::cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        std::cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                std::cout << bm.GetBusesForStop(q.stop) << std::endl;
                break;
            case QueryType::StopsForBus:
                std::cout << bm.GetStopsForBus(q.bus) << std::endl;
                break;
            case QueryType::AllBuses:
                std::cout << bm.GetAllBuses() << std::endl;
                break;
        }
    }

    return 0;
}