cmake_minimum_required(VERSION 2.6)
project (homework11_test)

include_directories(test/homework11_test/include)

add_executable(homework11_test src/homework11_test.cpp)
target_link_libraries(homework11_test gtest pthread)
