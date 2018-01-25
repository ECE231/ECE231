cmake_minimum_required(VERSION 2.6)
project (ECE231)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_subdirectory(homework00)
include_directories(homework00/include)
add_executable(homework00_test test/homework00_test.cpp)
target_link_libraries(homework00_test ${GTEST_LIBRARIES} pthread homework00)

add_subdirectory(homework02)
include_directories(homework02/include)
add_executable(homework02_test test/homework02_test.cpp)
target_link_libraries(homework02_test ${GTEST_LIBRARIES} pthread homework02)
