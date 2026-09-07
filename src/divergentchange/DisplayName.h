#pragma once

#include "divergentchange/StringManipulation.h"

#include <string>

class DisplayName
{
public:
    std::string format(const std::string& firstName, const std::string& lastName) const {
        return StringManipulation::trim(firstName) + " " + StringManipulation::toUpper(StringManipulation::trim(lastName));
    }
};
