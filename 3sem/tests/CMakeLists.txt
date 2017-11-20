 cmake_minimum_required(VERSION 2.8)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
 add_library(Catch INTERFACE)
 add_library(tester tester-main.cpp)

 project(11-test)
 add_executable(test-11 week11-test.cpp)
 target_link_libraries(test-11 Catch tester)