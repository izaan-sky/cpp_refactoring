#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "duplication/Forecast.h"
#include "duplication/WeatherReport.h"

using refactoring::duplication::Forecast;
using refactoring::duplication::WeatherReport;

TEST(WeatherReportTest, formatsMorningForecastCorrectly) {
    WeatherReport report;

    Forecast forecast("morning", 12.5, "Cloudy", 10);

    std::vector<std::string> output;
    report.formatDailyReport({forecast}, output);

    ASSERT_EQ(1u, output.size());
    EXPECT_EQ("Morning: 12.5°C, Cloudy, wind 10km/h", output[0]);
}

TEST(WeatherReportTest, formatsAfternoonForecastCorrectly) {
    WeatherReport report;

    Forecast forecast("afternoon", 8.0, "Rain", 20);

    std::vector<std::string> output;
    report.formatDailyReport({forecast}, output);

    ASSERT_EQ(1u, output.size());
    EXPECT_EQ("Afternoon: 8.0°C, Rain, wind 20km/h", output[0]);
}

TEST(WeatherReportTest, formatsEveningForecastCorrectly) {
    WeatherReport report;

    Forecast forecast("evening", 8.0, "Rain", 20);

    std::vector<std::string> output;
    report.formatDailyReport({forecast}, output);

    ASSERT_EQ(1u, output.size());
    EXPECT_EQ("Evening: 8.0°C, Rain, wind 20km/h", output[0]);
}

TEST(WeatherReportTest, formatsMultipleForecastsInOrder) {
    WeatherReport report;

    std::vector<Forecast> forecasts = {
            Forecast("morning", 10.0, "Sunny", 5),
            Forecast("night", 3.0, "Clear", 2)
    };

    std::vector<std::string> output;
    report.formatDailyReport(forecasts, output);

    ASSERT_EQ(2u, output.size());

    EXPECT_EQ("Morning: 10.0°C, Sunny, wind 5km/h", output[0]);
    EXPECT_EQ("Night: 3.0°C, Clear, wind 2km/h", output[1]);
}
