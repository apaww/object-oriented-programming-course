cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(temperaturesensor VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(temperaturesensorlib STATIC TemperatureSensor.cpp)

target_include_directories(temperaturesensorlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
