#pragma once 

#include <string>

class StringManipulation {
    public:
        static std::string trim(const std::string& s) {
            auto start = s.find_first_not_of(" \t\n\r\f\v");
            if (start == std::string::npos) {
                return "";
            }
            auto end = s.find_last_not_of(" \t\n\r\f\v");
            return s.substr(start, end - start + 1);
        }
};