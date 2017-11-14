 cmake_minimum_required(VERSION 2.8)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
 set(n 11)

 project(week${n})
 add_executable(${n}-A A.cpp)
 #add_executable(${n}-B B.cpp)
 #add_executable(${n}-C C.cpp)
 #add_executable(${n}-D D.cpp)