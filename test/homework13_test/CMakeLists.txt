cmake_minimum_required(VERSION 2.6)
project (homework13_test)

include_directories(test/homework13_test/include)

add_executable(homework13_test src/homework13_test.cpp)
target_link_libraries(homework13_test gtest pthread graph dijkstra compare_files)

add_custom_command(
  TARGET homework13_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/map.txt
  ${CMAKE_CURRENT_BINARY_DIR}/map.txt)
add_custom_command(
  TARGET homework13_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/correct_output1.txt
  ${CMAKE_CURRENT_BINARY_DIR}/correct_output1.txt)
add_custom_command(
  TARGET homework13_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/correct_output2.txt
  ${CMAKE_CURRENT_BINARY_DIR}/correct_output2.txt)
