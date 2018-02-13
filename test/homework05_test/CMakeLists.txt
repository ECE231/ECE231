cmake_minimum_required(VERSION 2.6)
project (homework05_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

include_directories(test/homework05_test/include)

add_executable(homework05_test src/homework05_test.cpp)
target_link_libraries(homework05_test ${GTEST_LIBRARIES} pthread homework05 compare_files)
