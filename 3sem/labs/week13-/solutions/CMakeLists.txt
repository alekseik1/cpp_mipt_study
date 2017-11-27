cmake_minimum_required(VERSION 2.9)

#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#set(${gtest_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/gtest/googletest)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(vector_tests vector_tests.cpp vector3d.cpp)

target_link_libraries(vector_tests gtest gtest_main)
