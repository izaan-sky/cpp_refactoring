#include "divergentchange/CustomerService.h"
#include "divergentchange/EmailValidation.h"
#include "divergentchange/StringManipulation.h"

#include <cctype>

namespace refactoring::divergentchange {

bool CustomerService::isValidEmail(const char* email) const {
    return EmailValidation::isValidEmail(email);
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
