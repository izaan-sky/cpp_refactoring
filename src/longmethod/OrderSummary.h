#pragma once

namespace refactoring::longmethod {

class OrderSummary {
public:
    OrderSummary(double subtotal, double discount, double tax, double total);

    double getSubtotal() const;
    double getDiscount() const;
    double getTax() const;
    double getTotal() const;

private:
    double subtotal_;
    double discount_;
    double tax_;
    double total_;
};

} // namespace refactoring::longmethod
