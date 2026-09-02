#include "comments/X1.h"

namespace refactoring::comments {

int X1::m(int lowerBound, int upperBound) {
    int sum = 0;

    for (int i = lowerBound; i <= upperBound; i++) {
        sum += square(i);
    }

    // Return accumulated sum
    return sum;
}

int X1::square(int k) {
    // Return square of input
    return k * k;
}

} // namespace refactoring::comments
