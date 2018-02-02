cmake_minimum_required(VERSION 2.6)
project (homework04_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

include_directories(test/homework04_test/include)

add_executable(homework04_test src/homework04_test.cpp)
target_link_libraries(homework04_test ${GTEST_LIBRARIES} pthread homework04 compare_files)
add_custom_command(
  TARGET homework04_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/good_input.txt
  ${CMAKE_CURRENT_BINARY_DIR}/good_input.txt)
add_custom_command(
  TARGET homework04_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/bad_input.txt
  ${CMAKE_CURRENT_BINARY_DIR}/bad_input.txt)
add_custom_command(
  TARGET homework04_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/correct_output.txt
  ${CMAKE_CURRENT_BINARY_DIR}/correct_output.txt)
