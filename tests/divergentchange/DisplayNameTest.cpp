#include "divergentchange/DisplayName.h"

#include <gtest/gtest.h>

class DisplayNameTest : public ::testing::Test {
protected:
    DisplayName service;
};

TEST_F(DisplayNameTest, formatDisplayName_shouldTrimAndUppercaseLastName) {
    std::string result = service.format(" John ", " smith ");
    EXPECT_EQ("John SMITH", result);
}

TEST_F(DisplayNameTest, formatDisplayName_shouldHandleEmptyStrings) {
    std::string result = service.format("", "");
    EXPECT_EQ(" ", result);
}

TEST_F(DisplayNameTest, formatDisplayName_shouldHandleSingleCharacterNames) {
    std::string result = service.format("A", "b");
    EXPECT_EQ("A B", result);
}
