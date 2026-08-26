#pragma once

#include <string>

namespace refactoring::duplication {

class Forecast {
public:
    Forecast(std::string period, double temperature, std::string condition, int windSpeed);

    double getTemperature() const;
    std::string getCondition() const;
    int getWindSpeed() const;

    bool isMorning() const;
    bool isAfternoon() const;
    bool isEvening() const;
    bool isNight() const;

private:
    std::string period_;
    double temperature_;
    std::string condition_;
    int windSpeed_;
};

} // namespace refactoring::duplication
