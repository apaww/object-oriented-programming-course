cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(1_TASK VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(addlib STATIC add.hpp add.cpp)

add_executable(test main.cpp)

target_link_libraries(test PUBLIC addlib)

