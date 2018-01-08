cmake_minimum_required(VERSION 2.6)
project(mycode)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

# Link runTests with what we want to test and the GTest and pthread library
add_library(mycode src/mycode.cpp)
add_executable(mycode_test test/mycode_test.cpp)
target_link_libraries(mycode_test ${GTEST_LIBRARIES} pthread mycode)

