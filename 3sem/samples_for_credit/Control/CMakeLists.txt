cmake_minimum_required(VERSION 3.0)

set(PVERSION 0.1)

project(control-var3 VERSION ${PVERSION})
    add_executable(PointND Point2D.cpp)

project(control-var3-test VERSION ${PVERSION})
    add_executable(point-tests point-tests.cpp)
    target_link_libraries(point-tests gtest gtest_main)
