cmake_minimum_required(VERSION 3.15)
project(HelloWorld)

include(makehello.cmake)

add_executable(HelloWorld main.cpp ${CMAKE_CURRENT_BINARY_DIR}/hello.h)

target_include_directories(HelloWorld PRIVATE
                             ${CMAKE_CURRENT_BINARY_DIR}
                             )