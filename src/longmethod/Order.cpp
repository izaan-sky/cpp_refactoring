#include "longmethod/Order.h"

namespace refactoring::longmethod {

Order::Order(std::optional<std::vector<OrderItem>> items, Customer customer)
    : items_(std::move(items)), customer_(customer) {}

OrderSummary Order::summarise() const {

    // Validation
    if (!items_.has_value()) {
        throw IllegalStateException("Items cannot be null");
    }
    if (items_->empty()) {
        throw IllegalStateException("Order must contain items");
    }

    // Subtotal calculation
    double subtotal = 0.0;
    for (const OrderItem& item : *items_) {
        subtotal += item.getPrice() * item.getQuantity();
    }

    // Discount rules
    double discount = 0.0;
    if (customer_.isLoyal()) {
        discount = subtotal * 0.10;
    } else if (subtotal > 100) {
        discount = subtotal * 0.05;
    }

    // Tax calculation
    double taxableAmount = subtotal - discount;
    double tax = taxableAmount * 0.20;

    // Total calculation
    double total = taxableAmount + tax;

    return OrderSummary(subtotal, discount, tax, total);
}

} // namespace refactoring::longmethod
