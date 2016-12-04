cmake_minimum_required(VERSION 3.2)
project(test_lib)

target_compile_definitions(test_lib PRIVATE _GLIBCXX_USE_CXX11_ABI=1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS system filesystem)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(test_lib ${SOURCE_FILES})
    target_link_libraries(test_lib ${Boost_LIBRARIES})
endif()

if (CMAKE_COMPILER_IS_GNUCC)
    target_link_libraries(test_lib pthread)
endif()
