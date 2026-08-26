#include "longparameterlist/ShippingNoteGenerator.h"

namespace refactoring::longparameterlist {

std::string ShippingNoteGenerator::generateShippingNote(
        const std::string& customerFirstName,
        const std::string& customerLastName,

        const std::string& addressLine1,
        const char* addressLine2,
        const std::string& city,
        const std::string& postcode,
        const std::string& country,

        const std::string& orderId,
        const std::string& itemDescription,
        int quantity) const {

    std::string fullName = customerFirstName + " " + customerLastName;

    std::string address = addressLine1 + ", "
            + (addressLine2 != nullptr ? std::string(addressLine2) + ", " : "")
            + city + ", "
            + postcode + ", "
            + country;

    return "SHIPPING NOTE\n"
            "Order: " + orderId + "\n"
            "Customer: " + fullName + "\n"
            "Ship To: " + address + "\n"
            "Item: " + itemDescription + "\n"
            "Quantity: " + std::to_string(quantity);
}

} // namespace refactoring::longparameterlist
