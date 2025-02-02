cmake_minimum_required(VERSION 3.15)
project(HelloWorld)

include(FetchContent)

# This declares the googletest repo but does not download it.
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# This downloads the googletest repo when you run `cmake ..`
FetchContent_MakeAvailable(googletest)

add_executable(HelloWorld main.cpp)
target_link_libraries(HelloWorld PRIVATE gtest_main)
