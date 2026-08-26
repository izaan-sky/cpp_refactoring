#include <gtest/gtest.h>

#include <optional>
#include <vector>

#include "longmethod/Customer.h"
#include "longmethod/Order.h"
#include "longmethod/OrderItem.h"
#include "longmethod/OrderSummary.h"

using refactoring::longmethod::Customer;
using refactoring::longmethod::IllegalStateException;
using refactoring::longmethod::Order;
using refactoring::longmethod::OrderItem;
using refactoring::longmethod::OrderSummary;

TEST(OrderTest, summarise_calculatesCorrectSummary_forNonLoyalCustomer_underThreshold) {
    Order order(
            std::vector<OrderItem>{
                    OrderItem(10.0, 2), // 20
                    OrderItem(5.0, 2)   // 10
            },
            Customer(false)
    );

    OrderSummary summary = order.summarise();

    EXPECT_DOUBLE_EQ(30.0, summary.getSubtotal());
    EXPECT_DOUBLE_EQ(0.0, summary.getDiscount());
    EXPECT_DOUBLE_EQ(6.0, summary.getTax());
    EXPECT_DOUBLE_EQ(36.0, summary.getTotal());
}

TEST(OrderTest, summarise_appliesLoyalCustomerDiscount) {
    Order order(
            std::vector<OrderItem>{ OrderItem(50.0, 1) },
            Customer(true)
    );

    OrderSummary summary = order.summarise();

    EXPECT_DOUBLE_EQ(50.0, summary.getSubtotal());
    EXPECT_DOUBLE_EQ(5.0, summary.getDiscount());
    EXPECT_DOUBLE_EQ(9.0, summary.getTax());
    EXPECT_DOUBLE_EQ(54.0, summary.getTotal());
}

TEST(OrderTest, summarise_appliesBulkDiscount_forNonLoyalCustomer_overThreshold) {
    Order order(
            std::vector<OrderItem>{ OrderItem(120.0, 1) },
            Customer(false)
    );

    OrderSummary summary = order.summarise();

    EXPECT_DOUBLE_EQ(120.0, summary.getSubtotal());
    EXPECT_DOUBLE_EQ(6.0, summary.getDiscount());
    EXPECT_DOUBLE_EQ(22.8, summary.getTax());
    EXPECT_DOUBLE_EQ(136.8, summary.getTotal());
}

// -------------------------
// Guard conditions
// -------------------------

TEST(OrderTest, summarise_throwsException_whenItemsIsNull) {
    Order order(std::nullopt, Customer(false));

    try {
        order.summarise();
        FAIL() << "Expected IllegalStateException";
    } catch (const IllegalStateException& ex) {
        EXPECT_STREQ("Items cannot be null", ex.what());
    }
}

TEST(OrderTest, summarise_throwsException_whenItemsIsEmpty) {
    Order order(std::vector<OrderItem>{}, Customer(false));

    try {
        order.summarise();
        FAIL() << "Expected IllegalStateException";
    } catch (const IllegalStateException& ex) {
        EXPECT_STREQ("Order must contain items", ex.what());
    }
}

// -------------------------
// Boundary test
// -------------------------

TEST(OrderTest, summarise_noDiscount_whenNonLoyalCustomer_atThreshold) {
    Order order(
            std::vector<OrderItem>{ OrderItem(100.0, 1) },
            Customer(false)
    );

    OrderSummary summary = order.summarise();

    EXPECT_DOUBLE_EQ(100.0, summary.getSubtotal());
    EXPECT_DOUBLE_EQ(0.0, summary.getDiscount());
    EXPECT_DOUBLE_EQ(20.0, summary.getTax());
    EXPECT_DOUBLE_EQ(120.0, summary.getTotal());
}
