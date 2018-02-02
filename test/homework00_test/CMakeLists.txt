cmake_minimum_required(VERSION 2.6)
project (homework00_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_executable(homework00_test src/homework00_test.cpp)
target_link_libraries(homework00_test ${GTEST_LIBRARIES} pthread homework00)
