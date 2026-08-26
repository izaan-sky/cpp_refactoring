#include "longmethod/Customer.h"

namespace refactoring::longmethod {

Customer::Customer(bool loyal) : loyal_(loyal) {}

bool Customer::isLoyal() const {
    return loyal_;
}

} // namespace refactoring::longmethod
