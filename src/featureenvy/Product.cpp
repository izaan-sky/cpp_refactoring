#include "featureenvy/Product.h"

namespace refactoring::featureenvy {

Product::Product(double price, bool onSale) : price_(price), onSale_(onSale) {}

double Product::calculateFinalPrice() const {
    double price = price_;

    if (onSale_) {
        price = price * 0.8;
    }

    return price;
}

} // namespace refactoring::featureenvy
