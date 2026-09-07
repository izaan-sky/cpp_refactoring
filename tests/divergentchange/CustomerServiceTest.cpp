#include <gtest/gtest.h>

#include "divergentchange/CustomerService.h"

using refactoring::divergentchange::CustomerService;

class CustomerServiceTest : public ::testing::Test {
protected:
    CustomerService service;
};

// -------------------------
// formatDisplayName tests
// -------------------------

TEST_F(CustomerServiceTest, formatDisplayName_shouldTrimAndUppercaseLastName) {
    std::string result = service.formatDisplayName(" John ", " smith ");
    EXPECT_EQ("John SMITH", result);
}

TEST_F(CustomerServiceTest, formatDisplayName_shouldHandleEmptyStrings) {
    std::string result = service.formatDisplayName("", "");
    EXPECT_EQ(" ", result);
}

TEST_F(CustomerServiceTest, formatDisplayName_shouldHandleSingleCharacterNames) {
    std::string result = service.formatDisplayName("A", "b");
    EXPECT_EQ("A B", result);
}

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