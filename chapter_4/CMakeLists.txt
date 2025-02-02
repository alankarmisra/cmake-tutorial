cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

if(WIN32)
    message(STATUS "Including windows_specific.cpp")
    set(EXTRA_SOURCES windows_specific.cpp)
else()
    message(STATUS "Including unix_specific.cpp")
    set(EXTRA_SOURCES unix_specific.cpp)
endif()

add_executable(HelloWorld main.cpp ${EXTRA_SOURCES})

set(MY_VARIABLE "Hello, CMake!")
message(STATUS "MY_VARIABLE is set to ${MY_VARIABLE}")

option(ENABLE_FEATURE "Enable a feature" ON)
if(ENABLE_FEATURE)
    message(STATUS "Feature is enabled")
else()
    message(STATUS "Feature is disabled")
endif()

find_package(Threads REQUIRED)
target_link_libraries(HelloWorld PRIVATE Threads::Threads)

add_library(MyLibrary STATIC my_library.cpp)
target_link_libraries(HelloWorld PRIVATE MyLibrary)