cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

# We want to run 
# `cmake -E echo "Build succeeded!"`
# after the build
add_custom_command(
    TARGET HelloWorld POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Build succeeded!"
    COMMENT "Running post-build step"
)