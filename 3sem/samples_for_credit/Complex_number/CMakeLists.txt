cmake_minimum_required(VERSION 3.0)

set(PVERSION 0.1)
set(TASK_NAME complex-number)

project(control-${TASK_NAME}-test VERSION ${PVERSION})
    add_executable(${TASK_NAME}-test complex_number-tests.cpp)
    add_library(${TASK_NAME} ComplexNumber.cpp)
    target_link_libraries(${TASK_NAME}-test ${TASK_NAME} gtest gtest_main)