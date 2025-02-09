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

# Conditional Builds

## Introduction

CMake allows you to conditionally include or exclude parts of your build based on variables, options, or system properties.

## Key Concepts

* **`if()`**: Used to conditionally execute CMake code.
* **`target_compile_definitions()`**: Adds compile definitions to a target.
* **`set()`**: Used to conditionally set variables.

## Code Sample

1. Create `windows_specific.cpp` file with some dummy code.

```cpp
// windows_specific.cpp
void windows_function() {}
```

2. Create `unix_specific.cpp` file with some dummy code.

```cpp
// unix_specific.cpp
void unix_function() {}
```

3. Edit the CMakeListsFile.txt to include the extra sources and add them to the executable.

```cmake
# CMakeListsFile.txt 
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# --- ADD THESE LINES ---
if(WIN32)
    message(STATUS "Including windows_specific.cpp")
    set(EXTRA_SOURCES windows_specific.cpp)
else()
    message(STATUS "Including unix_specific.cpp")
    set(EXTRA_SOURCES unix_specific.cpp)
endif()
# -----------------------

# --- EDIT THIS LINE TO INCLUDE ${EXTRA_SOURCES} ---
add_executable(HelloWorld main.cpp ${EXTRA_SOURCES})
# --------------------------------------------------

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
```

## Quiz

<details>

<summary>How do you check the operating system in CMake?</summary>

You can check the operating system using `if(WIN32)`, `if(APPLE)`, or `if(UNIX)`.

</details>

<details>

<summary>What does <code>target_compile_definitions</code> do?</summary>

`target_compile_definitions` adds compile definitions to a target. These definitions can be conditional using generator expressions.

</details>

<details>

<summary>Can you use <code>if</code> statements to control which files are compiled?</summary>

Yes, you can use `if` statements to control which files are compiled by conditionally adding them to `add_executable` or `add_library`.

</details>
