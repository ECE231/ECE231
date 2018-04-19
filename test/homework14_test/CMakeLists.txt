cmake_minimum_required(VERSION 2.6)
project (homework14_test)

include_directories(test/homework14_test/include)

add_executable(homework14_test src/homework14_test.cpp)
target_link_libraries(homework14_test gtest pthread employee compare_files)

add_custom_command(
  TARGET homework14_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/correct_output.txt
  ${CMAKE_CURRENT_BINARY_DIR}/correct_output.txt)
