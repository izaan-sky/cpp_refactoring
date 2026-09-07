#include "divergentchange/CustomerService.h"

#include <cctype>
#include <regex>

namespace refactoring::divergentchange {

namespace {

std::string toUpper(const std::string& s) {
    return StringManipulation::toUpper(s);
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
    return StringManipulation::trim(firstName) + " " + StringManipulation::toUpper(StringManipulation::trim(lastName));
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
