---
layout:
  title:
    visible: true
  description:
    visible: false
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: true
---

# Adding Libraries

## Introduction

CMake makes it easy to link libraries to your project. Libraries can be system libraries, third-party libraries, or libraries you build yourself.

## Key Concepts

* **`find_package()`**: Finds a system library or package.
* **`add_library()`**: Creates a library target.
* **`target_link_libraries()`**: Links libraries to a target.

## Code Sample

You can continue using the files from the previous chapter.

1. Create a new file my\_library.cpp with some dummy code

```cpp
// my_library.cpp
void my_library_func() {
  // noop
}
```

2. Edit the `CMakeLists.txt`

```cmake
# CMakeLists.txt 
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

set(MY_VARIABLE "Hello, CMake!")
message(STATUS "MY_VARIABLE is set to ${MY_VARIABLE}")

option(ENABLE_FEATURE "Enable a feature" ON)
if(ENABLE_FEATURE)
    message(STATUS "Feature is enabled")
else()
    message(STATUS "Feature is disabled")
endif()

# --- ADD THESE LINES ---
find_package(Threads REQUIRED)
target_link_libraries(HelloWorld PRIVATE Threads::Threads)

add_library(MyLibrary STATIC my_library.cpp)
target_link_libraries(HelloWorld PRIVATE MyLibrary)
```

## Quiz

<details>

<summary>What does <code>find_package</code> do?</summary>

`find_package` locates a system library or package. If `REQUIRED` is specified and the package isn’t found, CMake will stop with an error.

</details>

<details>

<summary>How do you create a static library in CMake?</summary>

You can create a static library using `add_library(MyLibrary STATIC ...)`.

</details>

<details>

<summary>What is the purpose of <code>target_link_libraries</code>?</summary>

`target_link_libraries` links the specified libraries to your executable or library target.

</details>
