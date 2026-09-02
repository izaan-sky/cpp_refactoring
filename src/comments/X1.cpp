#include "comments/X1.h"

namespace refactoring::comments {

int MathematicalOperations::sumSquaresInRange(int lowerBound, int upperBound) {
    int sum = 0;

    for (int i = lowerBound; i <= upperBound; i++) {
        sum += square(i);
    }

    return sum;
}

int MathematicalOperations::square(int input) {
    return input * input;
}

}
