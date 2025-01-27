cmake_minimum_required(VERSION 3.14)
project(Operators)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_divide tests/test_divide.cpp)
target_link_libraries(test_divide ${GTEST_BOTH_LIBRARIES})