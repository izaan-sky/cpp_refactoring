#pragma once

#include <string>

namespace refactoring::legacycode {

class Order {
public:
    Order(int orderId, std::string shippingType, double weightKg, double distanceKm, bool fragile);

    int getOrderId() const;
    const std::string& getShippingType() const;
    double getWeightKg() const;
    double getDistanceKm() const;
    bool isFragile() const;

private:
    int orderId_;
    std::string shippingType_;
    double weightKg_;
    double distanceKm_;
    bool fragile_;
};

} // namespace refactoring::legacycode
