#pragma once

#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

#include "longmethod/Customer.h"
#include "longmethod/OrderItem.h"
#include "longmethod/OrderSummary.h"

namespace refactoring::longmethod {

class IllegalStateException : public std::runtime_error {
public:
    explicit IllegalStateException(const std::string& message) : std::runtime_error(message) {}
};

class Order {
public:
    Order(std::optional<std::vector<OrderItem>> items, Customer customer);

    OrderSummary summarise() const;

private:
    std::optional<std::vector<OrderItem>> items_;
    Customer customer_;
};

} // namespace refactoring::longmethod
