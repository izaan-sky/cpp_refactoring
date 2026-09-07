#include "divergentchange/EmailValidation.h"

#include <gtest/gtest.h>

class EmailValidationTest : public ::testing::Test {
protected:
    EmailValidation service;
};

TEST_F(EmailValidationTest, isValidEmail_shouldReturnFalse_whenEmailIsNull) {
    EXPECT_FALSE(service.isValidEmail(nullptr));
}

TEST_F(EmailValidationTest, isValidEmail_shouldReturnFalse_whenEmailIsEmpty) {
    EXPECT_FALSE(service.isValidEmail(""));
}

TEST_F(EmailValidationTest, isValidEmail_shouldReturnFalse_whenMissingAtSymbol) {
    EXPECT_FALSE(service.isValidEmail("invalid.email.com"));
}

TEST_F(EmailValidationTest, isValidEmail_shouldReturnFalse_whenMissingLocalPart) {
    EXPECT_FALSE(service.isValidEmail("@domain.com"));
}

TEST_F(EmailValidationTest, isValidEmail_shouldReturnFalse_whenMissingDomain) {
    EXPECT_FALSE(service.isValidEmail("user@"));
}

TEST_F(EmailValidationTest, isValidEmail_shouldReturnTrue_whenEmailIsValid) {
    EXPECT_TRUE(service.isValidEmail("user.name+tag@example.com"));
}

TEST_F(EmailValidationTest, isValidEmail_shouldReturnTrue_whenSimpleValidEmail) {
    EXPECT_TRUE(service.isValidEmail("user@example.com"));
}
