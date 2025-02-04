cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(HelloWorld main.cpp)

# Add a test executable
add_executable(HelloWorldTest test.cpp)

# Link the google test library with our test executable
target_link_libraries(HelloWorldTest PRIVATE gtest_main)

# Enable testing
enable_testing()
add_test(NAME HelloWorldTest COMMAND HelloWorldTest)
