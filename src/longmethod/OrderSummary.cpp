#include "longmethod/OrderSummary.h"

namespace refactoring::longmethod {

OrderSummary::OrderSummary(double subtotal, double discount, double tax, double total)
    : subtotal_(subtotal), discount_(discount), tax_(tax), total_(total) {}

double OrderSummary::getSubtotal() const {
    return subtotal_;
}

double OrderSummary::getDiscount() const {
    return discount_;
}

double OrderSummary::getTax() const {
    return tax_;
}

double OrderSummary::getTotal() const {
    return total_;
}

} // namespace refactoring::longmethod
