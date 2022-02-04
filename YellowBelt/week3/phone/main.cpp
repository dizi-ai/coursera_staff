#include <sstream>
#include "phone_number.h"


PhoneNumber::PhoneNumber(const std::string &international_number) {
    std::stringstream phone_stream(international_number);
    std::string country_code, city_code, local_number;
    if (phone_stream) {
        getline(phone_stream, country_code, '-');
        getline(phone_stream, city_code, '-');
        getline(phone_stream, local_number, '\n');
    }
    if (country_code[0] != '+' || country_code.size() < 2) {
        throw std::invalid_argument("");
    }
    std::string tmp;
    for (int i = 1; i < country_code.size(); ++i) {
        tmp += country_code[i];
    }
    country_code_ = tmp;
    if (city_code.empty()) {
        throw std::invalid_argument("");
    }
    city_code_ = city_code;
    if (local_number.empty()) {
        throw std::invalid_argument("");
    }
    local_number_ = local_number;
}

std::string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

std::string PhoneNumber::GetCityCode() const {
    return city_code_;
}

std::string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

std::string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_+ "-" + city_code_ + "-" + local_number_;
}