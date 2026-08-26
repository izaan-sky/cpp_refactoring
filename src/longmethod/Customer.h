#pragma once

namespace refactoring::longmethod {

class Customer {
public:
    explicit Customer(bool loyal);

    bool isLoyal() const;

private:
    bool loyal_;
};

} // namespace refactoring::longmethod
