cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

################################
# GTest
################################
ADD_SUBDIRECTORY (gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

project(week2)
 add_subdirectory(contests/week2-/solutions)

project(week3)
 add_subdirectory(contests/week3-/solutions)

project(week4)
 add_subdirectory(labs/week4-/solutions)

project(week5)
 add_subdirectory(contests/week5-/solutions)

 add_subdirectory(labs/week6-/solutions/wiki-stats-cpp)

project(week7)
 add_subdirectory(contests/week7-/solutions)

project(week8)
 add_subdirectory(labs/week8-/solutions)

project(week9)
 add_subdirectory(contests/week9-/solutions)

project(week10)
 add_subdirectory(labs/week10-/solutions)

project(week11)
 add_subdirectory(contests/week11-/solutions)

add_subdirectory(labs/week12-/solutions)
add_subdirectory(labs/week13-/solutions)

# Tests
add_subdirectory(tests)

add_subdirectory(samples_for_credit/Control-2016-var-C)
add_subdirectory(samples_for_credit/Complex_number)