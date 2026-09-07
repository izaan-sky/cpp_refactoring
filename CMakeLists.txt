cmake_minimum_required(VERSION 3.16)
project(cpp_refactoring CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(refactoring_core
    src/comments/MathematicalOperations.cpp
    src/divergentchange/CustomerService.cpp
    src/divergentchange/DisplayName.h
    src/divergentchange/EmailValidation.h
    src/divergentchange/StringManipulation.h
    src/divergentchange/AccountStatus.h
    src/duplication/Forecast.cpp
    src/duplication/WeatherReport.cpp
    src/featureenvy/Product.cpp
    src/featureenvy/PriceCalculator.cpp
    src/longmethod/Customer.cpp
    src/longmethod/Order.cpp
    src/longmethod/OrderItem.cpp
    src/longmethod/OrderSummary.cpp
    src/longparameterlist/ShippingNoteGenerator.cpp
)
target_include_directories(refactoring_core PUBLIC src)

enable_testing()

add_executable(refactoring_tests
    tests/comments/MathematicalOperationsTest.cpp
    tests/divergentchange/AccountStatusTest.cpp
    tests/divergentchange/CustomerServiceTest.cpp
    tests/divergentchange/EmailValidationTest.cpp
    tests/duplication/WeatherReportTest.cpp
    tests/featureenvy/PriceCalculatorTest.cpp
    tests/longmethod/OrderTest.cpp
    tests/longparameterlist/ShippingNoteGeneratorTest.cpp
)
target_link_libraries(refactoring_tests PRIVATE refactoring_core GTest::gtest_main)

if(MINGW)
    target_link_options(refactoring_tests PRIVATE -static-libgcc -static-libstdc++ -static)
endif()

include(GoogleTest)
gtest_discover_tests(refactoring_tests)
