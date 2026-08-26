#include "duplication/Forecast.h"

namespace refactoring::duplication {

Forecast::Forecast(std::string period, double temperature, std::string condition, int windSpeed)
    : period_(std::move(period)), temperature_(temperature), condition_(std::move(condition)), windSpeed_(windSpeed) {}

double Forecast::getTemperature() const {
    return temperature_;
}

std::string Forecast::getCondition() const {
    return condition_;
}

int Forecast::getWindSpeed() const {
    return windSpeed_;
}

bool Forecast::isMorning() const {
    return period_ == "morning";
}

bool Forecast::isAfternoon() const {
    return period_ == "afternoon";
}

bool Forecast::isEvening() const {
    return period_ == "evening";
}

bool Forecast::isNight() const {
    return period_ == "night";
}

} // namespace refactoring::duplication
