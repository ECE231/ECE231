cmake_minimum_required(VERSION 2.6)
project(ECE231)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

# Link runTests with what we want to test and the GTest and pthread library
add_library(homework00 src/homework00.cpp)
add_executable(homework00_test test/homework00_test.cpp)
target_link_libraries(homework00_test ${GTEST_LIBRARIES} pthread homework00)

