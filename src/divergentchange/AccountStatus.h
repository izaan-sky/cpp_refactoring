#pragma once

#include <string>

class AccountStatus {
    public: 
        static std::string determineAccountStatus(int daysSinceLastLogin) {
            if (daysSinceLastLogin > 365) {
                return "INACTIVE";
            } else if (daysSinceLastLogin > 30) {
                return "DORMANT";
            }
            return "ACTIVE";
        }
};