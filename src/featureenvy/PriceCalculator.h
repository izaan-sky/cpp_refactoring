#pragma once

#include "featureenvy/Product.h"

namespace refactoring::featureenvy {

class PriceCalculator {
public:
    double calculateFinalPrice(const Product& product) const;
};

} // namespace refactoring::featureenvy
