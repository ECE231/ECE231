cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(homework09)

include_directories(include)
add_library(IntArray src/IntArray.cpp)
add_executable(homework09 src/homework09.cpp)
target_link_libraries(homework09 IntArray)
