cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
project (ECE231)

add_subdirectory(googletest)
add_subdirectory(test/compare_files)
include_directories(test/compare_files/include)

# if you want to compile this homework, set it to "if(1)"
if(1)
  add_subdirectory(homework14)
  include_directories(homework14/include)
  add_subdirectory(test/homework14_test)
endif()
