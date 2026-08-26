#include <gtest/gtest.h>

#include <string>

#include "longparameterlist/ShippingNoteGenerator.h"

using refactoring::longparameterlist::ShippingNoteGenerator;

class ShippingNoteGeneratorTest : public ::testing::Test {
protected:
    ShippingNoteGenerator shippingNoteGenerator;
};

TEST_F(ShippingNoteGeneratorTest, shouldGenerateShippingNoteWithAllInputFields) {

    std::string result = shippingNoteGenerator.generateShippingNote(
            "Jane",
            "Doe",

            "12 Baker Street",
            "Flat 4B",
            "London",
            "NW1 6XE",
            "UK",

            "ORD-123",
            "Wireless Headphones",
            2
    );

    EXPECT_NE(std::string::npos, result.find("Order: ORD-123"));
    EXPECT_NE(std::string::npos, result.find("Customer: Jane Doe"));
    EXPECT_NE(std::string::npos, result.find("Item: Wireless Headphones"));
    EXPECT_NE(std::string::npos, result.find("Quantity: 2"));

    EXPECT_NE(std::string::npos, result.find("12 Baker Street"));
    EXPECT_NE(std::string::npos, result.find("Flat 4B"));
    EXPECT_NE(std::string::npos, result.find("London"));
    EXPECT_NE(std::string::npos, result.find("NW1 6XE"));
    EXPECT_NE(std::string::npos, result.find("UK"));
}

TEST_F(ShippingNoteGeneratorTest, shouldIncludeCustomerFullName) {

    std::string result = shippingNoteGenerator.generateShippingNote(
            "John",
            "Smith",

            "1 High Street",
            "Apt 2",
            "Manchester",
            "M1 2AB",
            "UK",

            "ORD-999",
            "Laptop",
            1
    );

    EXPECT_NE(std::string::npos, result.find("Customer: John Smith"));
}

TEST_F(ShippingNoteGeneratorTest, shouldIncludeOrderIdAndItemDetails) {

    std::string result = shippingNoteGenerator.generateShippingNote(
            "Alice",
            "Brown",

            "50 King Street",
            "Unit 3",
            "Birmingham",
            "B1 1AA",
            "UK",

            "ORD-555",
            "Tablet",
            5
    );

    EXPECT_NE(std::string::npos, result.find("Order: ORD-555"));
    EXPECT_NE(std::string::npos, result.find("Item: Tablet"));
    EXPECT_NE(std::string::npos, result.find("Quantity: 5"));
}

TEST_F(ShippingNoteGeneratorTest, shouldIncludeFullAddressAcrossAllFields) {

    std::string result = shippingNoteGenerator.generateShippingNote(
            "Emma",
            "Jones",

            "99 High Road",
            "Floor 2",
            "Leeds",
            "LS1 4AB",
            "UK",

            "ORD-777",
            "Monitor",
            3
    );

    EXPECT_NE(std::string::npos, result.find("99 High Road"));
    EXPECT_NE(std::string::npos, result.find("Floor 2"));
    EXPECT_NE(std::string::npos, result.find("Leeds"));
    EXPECT_NE(std::string::npos, result.find("LS1 4AB"));
    EXPECT_NE(std::string::npos, result.find("UK"));
}

TEST_F(ShippingNoteGeneratorTest, shouldIncludeQuantityCorrectly) {

    std::string result = shippingNoteGenerator.generateShippingNote(
            "Tom",
            "White",

            "10 Market Street",
            "",
            "Liverpool",
            "L1 8JQ",
            "UK",

            "ORD-321",
            "Keyboard",
            10
    );

    EXPECT_NE(std::string::npos, result.find("Quantity: 10"));
}
