cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(homework03)

include_directories(include)
add_library(homework03 src/homework03.cpp)
add_executable(homework03_main src/homework03_main.cpp)
target_link_libraries(homework03_main homework03)
add_executable(homework03_cipher src/homework03_cipher.cpp)
target_link_libraries(homework03_cipher homework03)
