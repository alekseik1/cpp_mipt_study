cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Ofast -Wall")

################################
# GTest
################################
if(NOT DEFINED gtest_SOURCE_DIR)
 MESSAGE(STATUS "GTest not found, building it...")
 ADD_SUBDIRECTORY (gtest)
 enable_testing()
 include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
endif()
