#include <iostream>
#include <stdexcept>
#include <string>

#include "legacycode/ShippingCalculator.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Usage: shipping_app <orderId>" << std::endl;
        return 0;
    }

    int orderId = std::stoi(argv[1]);

    refactoring::legacycode::ShippingCalculator calculator;

    try {
        double cost = calculator.calculateShipping(orderId);

        std::cout << "Order ID: " << orderId << std::endl;
        std::cout << "Shipping cost: " << cost << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Failed to calculate shipping for order " << orderId << std::endl;
        std::cout << e.what() << std::endl;
    }

    return 0;
}
