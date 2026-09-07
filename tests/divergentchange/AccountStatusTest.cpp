#include "divergentchange/AccountStatus.h"

#include <gtest/gtest.h>

class AccountStatusTest : public ::testing::Test {
    protected:
        AccountStatus status;
};

TEST_F(AccountStatusTest, determineAccountStatus_shouldReturnInactive_whenDaysOver365) {
    EXPECT_EQ("INACTIVE", status.determineAccountStatus(366));
}

TEST_F(AccountStatusTest, determineAccountStatus_shouldReturnDormant_whenBetween31And365) {
    EXPECT_EQ("DORMANT", status.determineAccountStatus(100));
}

TEST_F(AccountStatusTest, determineAccountStatus_shouldReturnActive_when30DaysOrLess) {
    EXPECT_EQ("ACTIVE", status.determineAccountStatus(30));
    EXPECT_EQ("ACTIVE", status.determineAccountStatus(0));
}

TEST_F(AccountStatusTest, determineAccountStatus_shouldTreatNegativeDaysAsActive) {
    EXPECT_EQ("ACTIVE", status.determineAccountStatus(-10));
}
