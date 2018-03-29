cmake_minimum_required(VERSION 2.6)
project (homework09_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

include_directories(test/homework09_test/include)

add_executable(homework09_test src/homework09_test.cpp)
target_link_libraries(homework09_test ${GTEST_LIBRARIES} pthread IntArray)
