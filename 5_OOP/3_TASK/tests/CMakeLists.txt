enable_testing()

add_executable(test test.cpp)

target_link_libraries(test PUBLIC GTest::gtest_main)
target_link_libraries(test PUBLIC addlib)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/add)

include(GoogleTest)

gtest_discover_tests(test)

