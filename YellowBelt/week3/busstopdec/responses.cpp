#pragma once
#include "responses.h"
#include <iostream>

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r){
    if (r.buses.empty()) {
        os << "No stop" << std::endl;
    } else {
        for (const auto& bus : r.buses) {
            os << bus << " ";
        }
        os << std::endl;
    }
    return os;
}
std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
    if (r.stops.empty()) {
        os << "No bus" << std::endl;
    } else {
        for (const auto& stop_and_buses : r.stops) {
            os << "Stop " << stop_and_buses.first << ":";
            if (stop_and_buses.second.size() == 1) {
                os << " no interchange" << std::endl;
            } else {
                for (const auto& bus : stop_and_buses.second) {
                    if (bus != r.bus) {
                        os << " " << bus;
                    }
                }
                os << std::endl;
            }
        }
    }
    return os;
}
std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
    if (r.buses.empty()) {
        os << "No buses" << std::endl;
    } else {
        for (const auto& bus_and_stops : r.buses) {
            os << "Bus " << bus_and_stops.first << ":";
            for (const auto& stop : bus_and_stops.second) {
                os << " " << stop;
            }
            os << std::endl;
        }
    }
    return os;
}