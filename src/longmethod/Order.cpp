#include "longmethod/Order.h"

namespace refactoring::longmethod {

Order::Order(std::optional<std::vector<OrderItem>> items, Customer customer)
    : items_(std::move(items)), customer_(customer) {}

OrderSummary Order::summarise() const {
    validate();

    double subtotal = calculateSubtotal();

    double discount = calculateDiscount(subtotal);

    // Tax calculation
    double taxableAmount = 0.0;
    double tax = 0.0;

    // Total calculation
    double total = calculateTotal(subtotal, discount, taxableAmount, tax);

    return OrderSummary(subtotal, discount, tax, total);
}

double Order::calculateTotal(const double subtotal, const double discount, double &taxableAmount, double &tax) const
{
    taxableAmount = subtotal - discount;
    tax = taxableAmount * 0.20;
    double total = taxableAmount + tax;
    return total;
}

double Order::calculateDiscount(double subtotal) const
{
    double discount = 0.0;
    if (customer_.isLoyal())
    {
        discount = subtotal * 0.10;
    }
    else if (subtotal > 100)
    {
        discount = subtotal * 0.05;
    }

    return discount;
}

double Order::calculateSubtotal() const
{
    double subtotal = 0.0;
    for (const OrderItem &item : *items_)
    {
        subtotal += item.getPrice() * item.getQuantity();
    }

    return subtotal;
}

void Order::validate() const
{
    if (!items_.has_value())
    {
        throw IllegalStateException("Items cannot be null");
    }
    if (items_->empty())
    {
        throw IllegalStateException("Order must contain items");
    }
}

} // namespace refactoring::longmethod
