#include <gtest/gtest.h>

#include "featureenvy/PriceCalculator.h"
#include "featureenvy/Product.h"

using refactoring::featureenvy::PriceCalculator;
using refactoring::featureenvy::Product;

class PriceCalculatorTest : public ::testing::Test {
protected:
    PriceCalculator calculator;
};

TEST_F(PriceCalculatorTest, shouldApplyDiscountWhenProductIsOnSale) {
    Product product(100.0, true);

    double result = calculator.calculateFinalPrice(product);

    EXPECT_DOUBLE_EQ(80.0, result);
}

TEST_F(PriceCalculatorTest, shouldNotApplyDiscountWhenProductIsNotOnSale) {
    Product product(100.0, false);

    double result = calculator.calculateFinalPrice(product);

    EXPECT_DOUBLE_EQ(100.0, result);
}

TEST_F(PriceCalculatorTest, shouldReturnZeroWhenPriceIsZeroEvenIfOnSale) {
    Product product(0.0, true);

    double result = calculator.calculateFinalPrice(product);

    EXPECT_DOUBLE_EQ(0.0, result);
}
