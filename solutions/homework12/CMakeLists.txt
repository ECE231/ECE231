cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(homework11)

include_directories(include)
add_library(family_tree src/family_tree.cpp)
