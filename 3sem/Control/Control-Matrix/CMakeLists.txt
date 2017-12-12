project(Matrix-tests)
add_library(Matrix-lib Matrix.cpp)
add_executable(Matrix-tests Matrix-test.cpp)
target_link_libraries(Matrix-tests Matrix-lib gtest gtest_main)