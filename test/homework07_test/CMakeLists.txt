cmake_minimum_required(VERSION 2.6)
project (homework07_test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

include_directories(test/homework07_test/include)
include_directories(test/compare_files/include)

add_executable(homework07_test src/homework07_test.cpp)
target_link_libraries(homework07_test ${GTEST_LIBRARIES} pthread compare_files)
add_custom_command(
  TARGET homework07_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/ShortestPathMaze.txt
  ${CMAKE_CURRENT_BINARY_DIR}/ShortestPathMaze.txt)
add_custom_command(
  TARGET homework07_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/correct_output.txt
  ${CMAKE_CURRENT_BINARY_DIR}/correct_output.txt)
