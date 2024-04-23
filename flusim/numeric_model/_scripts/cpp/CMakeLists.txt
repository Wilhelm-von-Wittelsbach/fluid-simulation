cmake_minimum_required(VERSION 3.10)
project(fluidsim_lib)

set(CMAKE_CXX_STANDARD 11)

add_library(Burgers_LF SHARED Burgers_LF.cpp)
add_library(basic_fun SHARED basic_fun.cpp)
add_library(Burgers_MUSCL SHARED Burgers_MUSCL.cpp)
add_library(Burgers_WENO SHARED Burgers_WENO.cpp)



