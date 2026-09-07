#pragma once

#include <string>
#include "divergentchange/StringManipulation.h"

namespace refactoring::divergentchange {

class CustomerService {
public:
    bool isValidEmail(const char* email) const;
    std::string formatDisplayName(const std::string& firstName, const std::string& lastName) const;
    int calculateLoyaltyPoints(int numberOfPurchases) const;
    std::string determineAccountStatus(int daysSinceLastLogin) const;
};

} // namespace refactoring::divergentchange
