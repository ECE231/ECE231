cmake_minimum_required(VERSION 2.6)
project (homework10_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

include_directories(test/homework10_test/include)

add_executable(homework10_test src/homework10_test.cpp)
target_link_libraries(homework10_test ${GTEST_LIBRARIES} pthread homework10)
