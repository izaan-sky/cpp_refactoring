#include "divergentchange/CustomerService.h"

#include <algorithm>
#include <cctype>
#include <regex>

namespace refactoring::divergentchange {

namespace {

std::string trim(const std::string& s) {
    return StringManipulation::trim(s);
}

std::string toUpper(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
            [](unsigned char c) { return static_cast<char>(std::toupper(c)); });
    return result;
}

} // namespace

bool CustomerService::isValidEmail(const char* email) const {
    if (email == nullptr) {
        return false;
    }
    static const std::regex pattern("^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$");
    return std::regex_match(email, pattern);
}

std::string CustomerService::formatDisplayName(const std::string& firstName, const std::string& lastName) const {
    return trim(firstName) + " " + toUpper(trim(lastName));
}

int CustomerService::calculateLoyaltyPoints(int numberOfPurchases) const {
    return numberOfPurchases * 10;
}

std::string CustomerService::determineAccountStatus(int daysSinceLastLogin) const {
    if (daysSinceLastLogin > 365) {
        return "INACTIVE";
    } else if (daysSinceLastLogin > 30) {
        return "DORMANT";
    }
    return "ACTIVE";
}

} // namespace refactoring::divergentchange
