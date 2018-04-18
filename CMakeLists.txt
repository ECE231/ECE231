cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project (ECE231)

add_subdirectory(googletest)
add_subdirectory(test/compare_files)
include_directories(test/compare_files/include)

# if you want to compile this homework, set it to "if(1)"
if(1)
  add_subdirectory(homework13)
  include_directories(homework13/include)
  add_subdirectory(test/homework13_test)
endif()
