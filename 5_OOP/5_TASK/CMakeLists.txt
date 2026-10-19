cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(2_TASK VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_GTEST "Use gtest tests" OFF)

add_subdirectory(add)

add_executable(app main.cpp)
target_link_libraries(app PRIVATE addlib)

if(USE_GTEST)
    enable_testing()
    add_subdirectory(tests)
endif()
