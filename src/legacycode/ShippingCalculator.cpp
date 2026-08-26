#include "legacycode/ShippingCalculator.h"

#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

#include "legacycode/HttpGet.h"
#include "legacycode/Order.h"

namespace refactoring::legacycode {

namespace {

// Minimal extractor for the small, fixed-shape JSON payload returned by the
// orders API (orderId, shippingType, weightKg, distanceKm, fragile).
std::string extractJsonField(const std::string& json, const std::string& key) {
    std::string needle = "\"" + key + "\"";
    auto pos = json.find(needle);
    if (pos == std::string::npos) {
        throw std::runtime_error("Missing field: " + key);
    }
    pos = json.find(':', pos + needle.size());
    if (pos == std::string::npos) {
        throw std::runtime_error("Malformed field: " + key);
    }
    pos++;
    while (pos < json.size() && std::isspace(static_cast<unsigned char>(json[pos]))) {
        pos++;
    }
    if (pos < json.size() && json[pos] == '"') {
        auto end = json.find('"', pos + 1);
        return json.substr(pos + 1, end - pos - 1);
    }
    auto end = json.find_first_of(",}", pos);
    return json.substr(pos, end - pos);
}

Order parseOrder(const std::string& json) {
    return Order(
            std::stoi(extractJsonField(json, "orderId")),
            extractJsonField(json, "shippingType"),
            std::stod(extractJsonField(json, "weightKg")),
            std::stod(extractJsonField(json, "distanceKm")),
            extractJsonField(json, "fragile") == "true"
    );
}

} // namespace

double ShippingCalculator::calculateShipping(int orderId) const {

    try {
        std::string path = "/api/orders.php?orderId=" + std::to_string(orderId);

        std::string json = detail::httpGet("codemanship.co.uk", path);

        Order order = parseOrder(json);

        const std::string& shippingType = order.getShippingType();

        if (shippingType == "STANDARD") {
            return order.getWeightKg() * 0.5;
        }
        if (shippingType == "EXPRESS") {
            return order.getWeightKg() * 0.8 + order.getDistanceKm() * 0.1;
        }
        if (shippingType == "OVERNIGHT") {
            return order.getWeightKg() * 1.2 + 25;
        }

        throw std::runtime_error("Unknown shipping type: " + shippingType);

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return -1;
    }
}

} // namespace refactoring::legacycode
