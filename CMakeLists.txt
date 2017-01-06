cmake_minimum_required(VERSION 3.2)
project(test_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(test_lib ${SOURCE_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
message(STATUS "${CMAKE_SOURCE_DIR}")

if("${JSON_REPO_DIR} " STREQUAL " ")
    message(FATAL_ERROR "Json NOT found")
else()
    message(STATUS "Json found : ${JSON_REPO_DIR}/src")
    include_directories(${JSON_REPO_DIR}/src)
endif()

find_package(Boost REQUIRED COMPONENTS filesystem iostreams system thread)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(test_lib ${Boost_LIBRARIES})
endif()

find_package(OpenSSL)
if(OPENSSL_FOUND)
    message(STATUS "OpenSSL version: ${OPENSSL_VERSION}")
    include_directories(${OPENSSL_INCLUDE_DIRS})
    target_link_libraries(test_lib ${OPENSSL_LIBRARIES})
else()
    message(FATAL_ERROR "Openssl not found")
endif()
