#include "comments/X1.h"

namespace refactoring::comments {

int X1::m(int lowerBound, int upperBound) {
    int p = 0;

    // Iterate from lower bound (q) to upper bound (z)
    for (int i = lowerBound; i <= upperBound; i++) {
        // Add square of each number in the range
        p += n(i);
    }

    // Return accumulated sum
    return p;
}

int X1::n(int k) {
    // Return square of input
    return k * k;
}

} // namespace refactoring::comments
