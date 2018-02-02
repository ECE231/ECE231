cmake_minimum_required(VERSION 2.6)
project (homework02_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_executable(homework02_test src/homework02_test.cpp)
target_link_libraries(homework02_test ${GTEST_LIBRARIES} pthread homework02)
