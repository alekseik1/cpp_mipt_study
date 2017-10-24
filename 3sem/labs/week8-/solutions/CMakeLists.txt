cmake_minimum_required(VERSION 2.8)
project(wiki_stats)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES list_app.cpp linked_list.hpp)
add_executable(linked_list ${SOURCE_FILES})
