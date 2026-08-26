#include "featureenvy/PriceCalculator.h"

namespace refactoring::featureenvy {

double PriceCalculator::calculateFinalPrice(const Product& product) const {
    double price = product.getPrice();

    if (product.isOnSale()) {
        price = price * 0.8;
    }

    return price;
}

} // namespace refactoring::featureenvy
