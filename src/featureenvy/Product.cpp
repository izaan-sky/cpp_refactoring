#include "featureenvy/Product.h"

namespace refactoring::featureenvy {

Product::Product(double price, bool onSale) : price_(price), onSale_(onSale) {}

double Product::getPrice() const {
    return price_;
}

bool Product::isOnSale() const {
    return onSale_;
}

double Product::calculateFinalPrice() const {
    double price = getPrice();

    if (isOnSale()) {
        price = price * 0.8;
    }

    return price;
}

} // namespace refactoring::featureenvy
