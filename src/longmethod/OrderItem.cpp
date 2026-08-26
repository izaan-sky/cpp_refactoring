#include "longmethod/OrderItem.h"

namespace refactoring::longmethod {

OrderItem::OrderItem(double price, double quantity) : price_(price), quantity_(quantity) {}

double OrderItem::getPrice() const {
    return price_;
}

double OrderItem::getQuantity() const {
    return quantity_;
}

} // namespace refactoring::longmethod
