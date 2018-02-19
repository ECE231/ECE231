cmake_minimum_required(VERSION 2.6)
project (ECE231)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_subdirectory(test/compare_files)
include_directories(test/compare_files/include)

include_directories(StanfordCPPLib)

# if you want to compile this homework, set it to "if(1)"
if(0)
  add_subdirectory(homework00)
  include_directories(homework00/include)
  add_subdirectory(test/homework00_test)
endif()

# if you want to compile this homework, set it to "if(1)"
if(0)
  add_subdirectory(homework01)
  include_directories(homework01/include)
  add_subdirectory(test/homework01_test)
endif()

# if you want to compile this homework, set it to "if(1)"
if(0)
  add_subdirectory(homework02)
  include_directories(homework02/include)
  add_subdirectory(test/homework02_test)
endif()

# if you want to compile this homework, set it to "if(1)"
if(0)
  add_subdirectory(homework03)
  include_directories(homework03/include)
  add_subdirectory(test/homework03_test)
endif()

# if you want to compile this homework, set it to "if(1)"
if(0)
  add_subdirectory(homework04)
  include_directories(homework04/include)
  add_subdirectory(test/homework04_test)
endif()

# if you want to compile this homework, set it to "if(1)"
if(0)
  add_subdirectory(homework05)
  include_directories(homework05/include)
  add_subdirectory(test/homework05_test)
endif()

# if you want to compile this homework, set it to "if(1)"
if(1)
  add_subdirectory(homework07)
  include_directories(homework07/include)
  add_subdirectory(test/homework07_test)
endif()
