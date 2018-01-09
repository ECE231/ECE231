cmake_minimum_required(VERSION 2.6)
project(homework00)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

# Link runTests with what we want to test and the GTest and pthread library
add_library(homework00 src/homework00.cpp)

