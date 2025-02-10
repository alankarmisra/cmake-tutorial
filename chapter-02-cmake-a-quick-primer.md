# CMake : A Quick Primer

## Introduction

CMake is a build system generator that allows you to create build scripts (like Makefiles, Visual Studio projects, etc.) in a platform-independent way. It helps manage the build process for C/C++ projects.

## Key Concepts

* **CMakeLists.txt**: The main configuration file for CMake.
* **`cmake` command**: Used to generate build files.
* **`make` command**: Used to compile the project (on Unix-like systems).

## Code Sample


In this chapter, and beyond, we will be actively working with `CMake`. Grab your favourite text editor, and `C++` compiler and get ready to code.


1. Create a file `main.cpp`:


```cpp title="main.cpp" linenums="1"
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```


2. Create a `CMakeLists.txt` file in the same directory:


```cmake {title="CMakeLists.txt"}
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)
```


3. Build and run the project:


```bash
mkdir build
cd build
cmake ..
cmake --build . 
./HelloWorld
```


4. Output:


``` { .yaml .no-copy }
Hello, World!
```


## Quiz

<details>
<summary>What is the purpose of <code>cmake_minimum_required</code>?</summary>
<p>The purpose of `cmake_minimum_required` is to specify the minimum CMake version required to compile. If the current version is lower, it will throw an error.</p>
</details>

<details>

<summary>What does <code>add_executable</code> do?</summary>

<p>`add_executable` specifies the target executable name and associated source files.</p>

</details>

<details>

<summary>Why do we create a <code>build</code> directory?</summary>

<p>We create a `build` directory to separate the source from the build files.</p>

</details>
