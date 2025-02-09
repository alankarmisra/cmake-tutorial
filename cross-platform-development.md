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

# Cross-Platform Development

CMake makes it easy to write cross-platform build systems. In this lesson, we’ll cover:

* **Platform Detection**: Detect the operating system and compiler.
* **Conditional Compilation**: Use platform-specific code.
* **Toolchain Files**: Customize the build for different platforms.

#### Key Concepts

* **Platform Detection**: Use `if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")`, `if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")`, or `if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")` to detect the operating system.
* **Conditional Compilation**: Use `#ifdef` in your source code or generator expressions in CMake.
* **Toolchain Files**: Specify compilers, flags, and paths for cross-platform development.

#### Code Sample

Let’s detect the operating system and compiler.

1. Update your `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(CrossPlatformDemo)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    message(STATUS "Building on Windows")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    message(STATUS "Building on macOS")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message(STATUS "Building on Linux")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GCC")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    message(STATUS "Using Clang")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Using MSVC")
else()
  message(STATUS "Unknown compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

add_executable(HelloWorld main.cpp)
```

2. Write `main.cpp`

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

3. Build and run the program:

```bash
mkdir build
cd build
cmake ..
```

Output:

```
...
-- Building on macOS
-- Using Clang
...
```

### Quiz

1. How do you detect the operating system in CMake?
2. What is the purpose of `CMAKE_CXX_COMPILER_ID`?
3. How can you use toolchain files for cross-platform development?

### Answers

1. You detect the operating system using `if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")`, `if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")`, or `if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")`.
2. `CMAKE_CXX_COMPILER_ID` identifies the compiler being used (e.g., GCC, Clang, AppleClang, MSVC).
3. Toolchain files allow you to customize the build for different platforms by specifying compilers, flags, and paths.
