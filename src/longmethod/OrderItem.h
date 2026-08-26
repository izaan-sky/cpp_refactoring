#pragma once

namespace refactoring::longmethod {

class OrderItem {
public:
    OrderItem(double price, double quantity);

    double getPrice() const;
    double getQuantity() const;

private:
    double price_;
    double quantity_;
};

} // namespace refactoring::longmethod
