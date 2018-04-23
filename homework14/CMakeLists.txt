cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(homework14)

include_directories(include)
add_library(employee src/employee.cpp src/employee_sample.cpp)
add_executable(test_employee src/test_employee.cpp)
target_link_libraries(test_employee employee)
