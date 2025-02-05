cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# Add an executable
add_executable(HelloWorld main.cpp)

# Conditionally add a compile definition for Debug builds
target_compile_definitions(HelloWorld PRIVATE
    $<$<CONFIG:Debug>:DEBUG_MODE>  # Define DEBUG_MODE only in Debug builds
)

# Conditionally add a compiler flag for Debug builds
target_compile_options(HelloWorld PRIVATE
    $<$<CONFIG:Debug>:-O0>  # Disable optimizations in Debug builds
)