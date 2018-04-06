cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project (ECE231)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_subdirectory(test/compare_files)
include_directories(test/compare_files/include)

include_directories(StanfordCPPLib)

# if you want to compile this homework, set it to "if(1)"
if(1)
  add_subdirectory(homework11)
  include_directories(homework11/include)
  add_subdirectory(test/homework11_test)
endif()
