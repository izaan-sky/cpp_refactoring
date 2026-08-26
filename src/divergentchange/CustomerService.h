#pragma once

#include <string>

namespace refactoring::divergentchange {

class CustomerService {
public:
    bool isValidEmail(const char* email) const;
    std::string formatDisplayName(const std::string& firstName, const std::string& lastName) const;
    int calculateLoyaltyPoints(int numberOfPurchases) const;
    std::string determineAccountStatus(int daysSinceLastLogin) const;
};

} // namespace refactoring::divergentchange
