cmake_minimum_required(VERSION 3.5)
project(test_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost COMPONENTS filesystem system)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(test_lib ${Boost_LIBRARIES})
endif()

set(SOURCE_FILES main.cpp)
add_executable(test_lib ${SOURCE_FILES})
