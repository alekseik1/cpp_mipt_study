 cmake_minimum_required(VERSION 2.8)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

 project(tests)
 add_executable(test-all tester-main.cpp)