#include "divergentchange/CustomerService.h"

#include "divergentchange/AccountStatus.h"
#include "divergentchange/DisplayName.h"
#include "divergentchange/EmailValidation.h"

#include <cctype>

namespace refactoring::divergentchange {

bool CustomerService::isValidEmail(const char* email) const {
    return EmailValidation::isValidEmail(email);
}

std::string CustomerService::formatDisplayName(const std::string& firstName, const std::string& lastName) const {
    return DisplayName::format(firstName, lastName);
}

int CustomerService::calculateLoyaltyPoints(int numberOfPurchases) const {
    return numberOfPurchases * 10;
}

std::string CustomerService::determineAccountStatus(int daysSinceLastLogin) const {
    return AccountStatus::determineAccountStatus(daysSinceLastLogin);
}

} // namespace refactoring::divergentchange
