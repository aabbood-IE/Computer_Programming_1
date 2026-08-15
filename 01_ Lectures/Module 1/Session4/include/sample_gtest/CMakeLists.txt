cmake_minimum_required(VERSION 3.28)
project(MyTriangleProject)

if (CMAKE_BUILD_TYPE MATCHES "Release")
    add_executable(triangle triangle.c)
else()
    add_library(triangle_lib triangle.c)
endif()

