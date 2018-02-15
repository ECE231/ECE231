cmake_minimum_required(VERSION 2.6)
project (homework06_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

include_directories(test/homework06_test/include)

add_executable(homework06_test src/homework06_test.cpp)
target_link_libraries(homework06_test ${GTEST_LIBRARIES} pthread homework06 compare_files)
