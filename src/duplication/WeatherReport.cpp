#include "duplication/WeatherReport.h"

#include <charconv>

namespace refactoring::duplication {

namespace {

// Mimics java.lang.Double#toString: shortest round-trip representation,
// always with a decimal point (e.g. 8.0, not 8).
std::string javaDoubleToString(double value) {
    char buffer[64];
    auto result = std::to_chars(buffer, buffer + sizeof(buffer), value);
    std::string text(buffer, result.ptr);
    if (text.find('.') == std::string::npos &&
        text.find('e') == std::string::npos &&
        text.find('E') == std::string::npos) {
        text += ".0";
    }
    return text;
}

} // namespace

void WeatherReport::formatDailyReport(const std::vector<Forecast>& forecasts, std::vector<std::string>& output) {

    for (const Forecast& forecast : forecasts) {

        if (forecast.isMorning()) {
            std::string line = "Morning: " + javaDoubleToString(forecast.getTemperature()) + "°C, "
                    + forecast.getCondition() + ", wind " + std::to_string(forecast.getWindSpeed()) + "km/h";
            output.push_back(line);
        }

        if (forecast.isAfternoon()) {
            std::string line = "Afternoon: " + javaDoubleToString(forecast.getTemperature()) + "°C, "
                    + forecast.getCondition() + ", wind " + std::to_string(forecast.getWindSpeed()) + "km/h";
            output.push_back(line);
        }

        if (forecast.isEvening()) {
            std::string line = "Evening: " + javaDoubleToString(forecast.getTemperature()) + "°C, "
                    + forecast.getCondition() + ", wind " + std::to_string(forecast.getWindSpeed()) + "km/h";
            output.push_back(line);
        }

        if (forecast.isNight()) {
            std::string line = "Night: " + javaDoubleToString(forecast.getTemperature()) + "°C, "
                    + forecast.getCondition() + ", wind " + std::to_string(forecast.getWindSpeed()) + "km/h";
            output.push_back(line);
        }
    }
}

} // namespace refactoring::duplication
