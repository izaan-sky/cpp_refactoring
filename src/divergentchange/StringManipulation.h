#pragma once 

#include <string>
#include <algorithm>

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

        static std::string toUpper(const std::string& s) {
            std::string result = s;
            std::transform(result.begin(), result.end(), result.begin(),
                    [](unsigned char c) { return static_cast<char>(std::toupper(c)); });
            return result;
        }
};