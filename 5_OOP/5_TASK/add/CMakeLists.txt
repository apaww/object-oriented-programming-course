cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(2_TASK VERSION 0.0.1 LANGUAGES CXX)

add_library(addlib INTERFACE)

target_include_directories(addlib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

