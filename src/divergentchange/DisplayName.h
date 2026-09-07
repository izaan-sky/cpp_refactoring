#pragma once

#include "divergentchange/StringManipulation.h"

#include <string>

class DisplayName
{
public:
    static std::string format(const std::string& firstName, const std::string& lastName) {
        return StringManipulation::trim(firstName) + " " + StringManipulation::toUpper(StringManipulation::trim(lastName));
    }
};
