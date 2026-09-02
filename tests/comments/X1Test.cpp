#include <gtest/gtest.h>

#include "comments/MathematicalOperations.h"

using refactoring::comments::MathematicalOperations;

TEST(MathematicalOperationsTest, sumsSquaresFrom7To12) {
    int a = 7;
    int b = 12;

    // Expected: sum of squares from 7 to 12
    int expected = 0;
    for (int i = a; i <= b; i++) {
        expected += i * i;
    }

    int actual = MathematicalOperations::sumSquaresInRange(a, b);

    EXPECT_EQ(expected, actual);
}
