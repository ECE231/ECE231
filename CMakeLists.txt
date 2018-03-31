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
if(0)
  add_subdirectory(homework09)
  include_directories(homework09/include)
  add_subdirectory(test/homework09_test)
endif()

# if you want to compile this homework, set it to "if(1)"
if(1)
  add_subdirectory(homework10)
  include_directories(homework10/include)
  add_subdirectory(test/homework10_test)
endif()
