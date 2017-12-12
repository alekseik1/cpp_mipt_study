cmake_minimum_required(VERSION 3.0)

set(PVERSION 0.1)

project(control-var3-point VERSION ${PVERSION})
    add_executable(PointND PointND.cpp)

project(control-var3-point-test VERSION ${PVERSION})
    add_executable(point-tests point-tests.cpp)
    add_library(point-nd PointND.cpp)
    target_link_libraries(point-tests point-nd gtest gtest_main)

project(control-var3-vector VERSION ${PVERSION})
    add_executable(VectorND VectorND.cpp)
    target_link_libraries(VectorND point-nd)

project(control-var3-vector-test VERSION ${PVERSION})
    add_executable(vector-tests vector-tests.cpp)
    add_library(vector-nd VectorND.cpp)
    target_link_libraries(vector-tests vector-nd point-nd gtest gtest_main)