cmake_minimum_required(VERSION 2.6)
project (homework03_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_executable(homework03_test src/homework03_test.cpp)
target_link_libraries(homework03_test ${GTEST_LIBRARIES} pthread homework03 compare_files)
add_custom_command(
  TARGET homework03_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/tab_input.txt
  ${CMAKE_CURRENT_BINARY_DIR}/tab_input.txt)
add_custom_command(
  TARGET homework03_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/tab_correct_result.txt
  ${CMAKE_CURRENT_BINARY_DIR}/tab_correct_result.txt)
