cmake_minimum_required(VERSION 3.28)
project(MyProject LANGUAGES C CXX)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    enable_testing()
endif()

add_subdirectory(include/sample_gtest)
add_subdirectory(tests)