cmake_minimum_required(VERSION 2.6)
project (compare_files)

include_directories(include)
add_library(compare_files src/compare_files.cpp)
