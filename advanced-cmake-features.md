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

# Advanced CMake Features

## Introduction

CMake has several advanced features that can make your build system more powerful and flexible. In this lesson, we’ll cover:

* **Generator Expressions**: Dynamic expressions evaluated at build time.
* **Toolchain Files**: Customize the build for different compilers or platforms.
* **Exporting and Importing Targets**: Share targets between projects.

## Key Concepts

* **Generator Expressions**: Allow you to write dynamic CMake code that adapts to the build configuration.
* **Toolchain Files**: Specify compilers, flags, and paths for cross-platform development.
* **Exporting Targets**: Share targets between projects using `export()` and `install(EXPORT)`.

## Code Sample

1. Update your `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(GeneratorExpressionsDemo)

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
```

2. Write `main.cpp`:

```cpp
#include <iostream>

int main() {
#ifdef DEBUG_MODE
    std::cout << "Hello World from Debug mode!" << std::endl;
#else
    std::cout << "Hello World from Release mode!" << std::endl;
#endif
    return 0;
}
```

3. Build in Debug and Release modes:

```bash
mkdir build-debug
cd build-debug
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .
./HelloWorld

cd ..
mkdir build-release
cd build-release
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
./HelloWorld
```

Output (Debug):

```bash
Hello World from Debug mode!
```

Output (Release):

```bash
Hello World from Release mode!
```

## Quiz

<details>

<summary>What is the purpose of generator expressions?</summary>

Generator expressions allow you to write dynamic CMake code that adapts to the build configuration.

</details>

<details>

<summary>How do you conditionally add a compiler flag for Debug builds?</summary>

You can conditionally add a compiler flag using `target_compile_options(MyTarget PRIVATE $<$<CONFIG:Debug>:-O0>)`.

</details>

<details>

<summary>What does <code>$&#x3C;CONFIG:Debug></code> evaluate to in Release mode?</summary>

`$<CONFIG:Debug>` evaluates to `0` (false) in Release mode.

</details>
