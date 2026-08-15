cmake_minimum_required(VERSION 3.28)
project(myTestProject LANGUAGES C CXX)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    find_package(GTest REQUIRED)
    include(GoogleTest) # include the GoogleTest CMake module
    include_directories(${GTEST_INCLUDE_DIRS})
    # Link our tests code with what we want to test and the GTest and pthread library
    add_executable(tests mytests.cpp)
    target_link_libraries(tests ${GTEST_LIBRARIES})
    gtest_discover_tests(tests) # discovers tests by asking the compiled test executable to enumerate its tests
endif()