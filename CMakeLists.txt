cmake_minimum_required(VERSION 3.2)
project(test_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

#set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS filesystem iostreams system thread)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(test_lib ${SOURCE_FILES})
    target_link_libraries(test_lib ${Boost_LIBRARIES})
endif()
