cmake_minimum_required(VERSION 3.0)

set(PVERSION 0.1)

project(control-var3 VERSION ${PVERSION})
    add_executable(PointND Point2D.cpp)

project(control-var3-test VERSION ${PVERSION})
    add_executable(point-tests point-tests.cpp)
    add_library(point-nd Point2D.cpp)
    target_link_libraries(point-tests point-nd gtest gtest_main)
