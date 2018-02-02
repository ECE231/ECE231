cmake_minimum_required(VERSION 2.6)
project (homework01_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_executable(homework01_test src/homework01_test.cpp)
target_link_libraries(homework01_test ${GTEST_LIBRARIES} pthread homework01)
