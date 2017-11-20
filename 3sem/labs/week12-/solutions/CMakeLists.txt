cmake_minimum_required(VERSION 2.8)
project(arithmetical_dragons)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES arithmetical_dragons.cpp hero.h unit.h dragon.h)
add_library(unit STATIC unit.h)
add_library(dragon STATIC dragon.h)
add_library(hero STATIC hero.h)

set_target_properties(dragon unit hero PROPERTIES LINKER_LANGUAGE CXX)
add_executable(arithmetical_dragons ${SOURCE_FILES})

target_link_libraries(arithmetical_dragons unit hero dragon)