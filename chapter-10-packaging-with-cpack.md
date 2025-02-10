# Packaging with CPack

## Introduction

CPack is a tool that comes bundled with CMake. It allows you to create platform-specific packages for your project, such as:

* **`.dmg`**: Disk Image (common on macOS).
* **`.tar.gz`**: Compressed archive (common on Unix-like systems).
* **`.zip`**: Compressed archive (common on Windows).

## Key Concepts

* **`install()`**: Specifies files or targets to include in the package.
* **`include(CPack)`**: Enables CPack and generates packaging targets.
* **CPack Generators**: Specify the type of package to create (e.g., `DragNDrop` for `.dmg`).

## Code Sample

Let’s create a simple project and package it for macOS.

1. Update your `CMakeLists.txt`:


```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

install(TARGETS HelloWorld DESTINATION bin)

set(CPACK_PACKAGE_NAME "HelloWorld")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "A simple program packaged with CPack")
set(CPACK_GENERATOR "DragNDrop;TGZ")
include(CPack)
```


2. Write `main.cpp`


```cpp
#include <iostream>
int main() {
    std::cout << "Hello from MyProgram!" << std::endl;
    return 0;
}
```


3. Build and package the project:


```bash
mkdir build
cd build
cmake ..
cmake --build .
cpack
```


Output:


```bash
CPack: Create package using DragNDrop
CPack: Install projects
CPack: - Run preinstall target for: HelloWorld
CPack: - Install project: HelloWorld []
CPack: Create package
CPack: - package: /path/to/build/HelloWorld-1.0.0-Darwin.dmg generated.
CPack: Create package using TGZ
CPack: Install projects
CPack: - Run preinstall target for: HelloWorld
CPack: - Install project: HelloWorld []
CPack: Create package
CPack: - package: /path/to/build/HelloWorld-1.0.0-Darwin.tar.gz generated.
```


4. Check the generated packages

* `HelloWorld-1.0.0-Darwin.dmg`: A macOS disk image
* `HelloWorld-1.0.0-Darwin.tar.gz`: A compressed archive.

## Quiz

<details>

<summary>What does the <code>install()</code> command do?</summary>

The `install()` command specifies which files or targets should be included in the package and where they should be installed.

</details>

<details>

<summary>How do you specify the type of package to create with CPack?</summary>

You specify the type of package using the `CPACK_GENERATOR` variable (e.g., `DragNDrop` for `.dmg`).

</details>

<details>

<summary>What is the purpose of <code>include(CPack)</code>?</summary>

`include(CPack)` enables CPack and generates the necessary packaging targets.

</details>
