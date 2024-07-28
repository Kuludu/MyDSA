cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)

project(Search)

add_executable(Search example.cpp)
add_compile_options(
    -Wall
    -O2
)

enable_testing()
add_executable(test_lower_bound test_lower_bound.cpp)
add_test(NAME test_lower_bound COMMAND test_lower_bound)
add_executable(test_upper_bound test_upper_bound.cpp)
add_test(NAME test_upper_bound COMMAND test_upper_bound)