cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(homework13)

include_directories(include)
add_library(dijkstra src/dijkstra.cpp)
add_library(graph src/graph.cpp src/graph_base.cpp)
add_executable(test_dijkstra src/test_dijkstra.cpp)
target_link_libraries(test_dijkstra dijkstra graph)
