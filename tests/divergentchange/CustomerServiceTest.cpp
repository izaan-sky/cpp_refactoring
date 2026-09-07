#include <gtest/gtest.h>

#include "divergentchange/CustomerService.h"

using refactoring::divergentchange::CustomerService;

class CustomerServiceTest : public ::testing::Test {
protected:
    CustomerService service;
};

// -------------------------
// calculateLoyaltyPoints tests
// -------------------------

TEST_F(CustomerServiceTest, calculateLoyaltyPoints_shouldReturnZero_whenNoPurchases) {
    EXPECT_EQ(0, service.calculateLoyaltyPoints(0));
}

TEST_F(CustomerServiceTest, calculateLoyaltyPoints_shouldCalculateCorrectly_forPositiveValues) {
    EXPECT_EQ(50, service.calculateLoyaltyPoints(5));
}

TEST_F(CustomerServiceTest, calculateLoyaltyPoints_shouldHandleLargeNumbers) {
    EXPECT_EQ(100000, service.calculateLoyaltyPoints(10000));
}

TEST_F(CustomerServiceTest, calculateLoyaltyPoints_shouldAllowNegativeValues_butStillMultiply) {
    EXPECT_EQ(-50, service.calculateLoyaltyPoints(-5));
}
