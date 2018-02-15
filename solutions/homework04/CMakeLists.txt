cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(homework04)

include_directories(include)
add_library(homework04 src/homework04.cpp)
add_executable(histogram src/histogram.cpp)
target_link_libraries(histogram homework04)
