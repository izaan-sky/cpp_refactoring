#pragma once

#include <regex>

class EmailValidation
{
public:
    static bool isValidEmail(const char* email) {
        if (email == nullptr) {
            return false;
        }
        static const std::regex pattern("^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$");
        return std::regex_match(email, pattern);
    }
};
