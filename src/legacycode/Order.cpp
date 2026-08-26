#include "legacycode/Order.h"

namespace refactoring::legacycode {

Order::Order(int orderId, std::string shippingType, double weightKg, double distanceKm, bool fragile)
    : orderId_(orderId), shippingType_(std::move(shippingType)), weightKg_(weightKg),
      distanceKm_(distanceKm), fragile_(fragile) {}

int Order::getOrderId() const {
    return orderId_;
}

const std::string& Order::getShippingType() const {
    return shippingType_;
}

double Order::getWeightKg() const {
    return weightKg_;
}

double Order::getDistanceKm() const {
    return distanceKm_;
}

bool Order::isFragile() const {
    return fragile_;
}

} // namespace refactoring::legacycode
