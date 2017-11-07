cmake_minimum_required(VERSION 2.8)
project(wiki_stats)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Fraction.cpp)
add_executable(fraction ${SOURCE_FILES})
