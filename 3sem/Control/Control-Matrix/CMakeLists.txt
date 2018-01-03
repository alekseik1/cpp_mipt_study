
project(Matrix-tests)
    add_library(Matrix-lib SquareMatrix.hpp)
    add_executable(Matrix-tests SquareMatrix-test.cpp)
    set_target_properties(Matrix-lib PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries(Matrix-tests gtest gtest_main)