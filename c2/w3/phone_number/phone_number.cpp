#include "phone_number.h"
#include <stdexcept>
#include <iostream>

void TryGetCode(const string& international_number, string& code, int& inter_pointer) {
    for (int i = inter_pointer; i < international_number.size(); i++) {
        if (international_number[i] == '-' || i == international_number.size() - 1) {
            inter_pointer = i + 1; // jump to next number
            break;
        }
        code += international_number[i];
    }
    if (code.size() == 0) {
        throw invalid_argument("");
    }
}

PhoneNumber::PhoneNumber(const string& international_number){
    if (international_number.size() == 0 || international_number[0] != '+') {
        throw invalid_argument("");
    }
    int inter_pointer = 1;
    // try get country code
    TryGetCode(international_number, country_code_, inter_pointer);
    // try get city code
    TryGetCode(international_number, city_code_, inter_pointer);
    // try get local number
    for (int i = inter_pointer; i < international_number.size(); i++)
    {
        local_number_ += international_number[i];
    }
    if (local_number_.size() == 0) {
        throw invalid_argument("");
    }
}

string PhoneNumber::GetCityCode() const{
    return city_code_;
}

string PhoneNumber::GetCountryCode() const{
    return country_code_;
}

string PhoneNumber::GetLocalNumber() const{
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const{
    return "+" + GetCountryCode() + "-" + GetCityCode() + "-" + GetLocalNumber();
}

