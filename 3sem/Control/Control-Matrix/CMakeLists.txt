project(Matrix-tests)
add_library(Matrix-lib SquareMatrix.cpp)
add_executable(Matrix-tests SquareMatrix-test.cpp)
target_link_libraries(Matrix-tests Matrix-lib gtest gtest_main)