cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(2_TASK VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(USE_GTEST "Use gtest tests" OFF)

add_subdirectory(TemperatureSensor)

add_executable(og main.cpp)
target_link_libraries(og PRIVATE temperaturesensorlib)

if(USE_GTEST)
    enable_testing()
    add_subdirectory(tests)
endif()
