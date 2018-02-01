cmake_minimum_required(VERSION 2.6)
project (ECE231)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_subdirectory(grading)
include_directories(grading/include)

add_subdirectory(homework00)
include_directories(homework00/include)
add_executable(homework00_test test/homework00_test.cpp)
target_link_libraries(homework00_test ${GTEST_LIBRARIES} pthread homework00)

# if you want to compile HW01, uncomment these lines
#add_subdirectory(homework01)
#include_directories(homework01/include)
#add_executable(homework01_test test/homework01_test.cpp)
#target_link_libraries(homework01_test ${GTEST_LIBRARIES} pthread homework01)

#add_subdirectory(homework02)
#include_directories(homework02/include)
#add_executable(homework02_test test/homework02_test.cpp)
#target_link_libraries(homework02_test ${GTEST_LIBRARIES} pthread homework02)

add_subdirectory(homework03)
include_directories(homework03/include)
add_executable(homework03_test test/homework03_test.cpp)
target_link_libraries(homework03_test ${GTEST_LIBRARIES} pthread homework03)
add_custom_command(
        TARGET homework03_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/test/tab_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/tab_input.txt)
add_custom_command(
        TARGET homework03_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/test/tab_correct_result.txt
                ${CMAKE_CURRENT_BINARY_DIR}/tab_correct_result.txt)

add_subdirectory(homework04)
include_directories(homework04/include)
add_executable(homework04_test test/homework04_test.cpp)
target_link_libraries(homework04_test ${GTEST_LIBRARIES} pthread homework04 compare_files)
add_custom_command(
        TARGET homework04_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/test/good_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/good_input.txt)
add_custom_command(
        TARGET homework04_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/test/bad_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/bad_input.txt)
add_custom_command(
        TARGET homework04_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/test/correct_output.txt
                ${CMAKE_CURRENT_BINARY_DIR}/correct_output.txt)
