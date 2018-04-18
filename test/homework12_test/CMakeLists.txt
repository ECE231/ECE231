cmake_minimum_required(VERSION 2.6)
project (homework12_test)

include_directories(test/homework12_test/include)
add_executable(family src/family.cpp)
target_link_libraries(family family_tree)

add_executable(homework12_test src/homework12_test.cpp)
target_link_libraries(homework12_test gtest pthread family_tree compare_files)

add_custom_command(
  TARGET homework12_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/family.txt
  ${CMAKE_CURRENT_BINARY_DIR}/family.txt)
add_custom_command(
  TARGET homework12_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/data/correct_output.txt
  ${CMAKE_CURRENT_BINARY_DIR}/correct_output.txt)
