cmake_minimum_required(VERSION 2.7)
project(test_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(test_lib ${SOURCE_FILES})