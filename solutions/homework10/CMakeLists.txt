cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(homework10)

include_directories(include)
add_library(homework10 src/editor_buffer.cpp)

