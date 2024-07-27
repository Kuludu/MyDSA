cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)

project(Search)

add_executable(Search example.cpp)
add_compile_options(
    -Wall
    -O2
)

enable_testing()
