cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(homework05)

include_directories(include)
add_library(homework05 src/rational.cpp)

