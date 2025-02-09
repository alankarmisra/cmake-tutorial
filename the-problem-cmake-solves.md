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

# The problem CMake solves

CMake is a build system generator that allows you to create build scripts (like Makefiles, Visual Studio projects, etc.) in a platform-independent way. It helps manage the build process for C/C++ projects.

## Key Concepts

* **CMakeLists.txt**: The main configuration file for CMake.
* **`cmake` command**: Used to generate build files.
* **`make` command**: Used to compile the project (on Unix-like systems).

## Code Sample

1. Create a file `main.cpp`:

{% code title="main.cpp" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```cpp
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```
{% endcode %}

2. Create a `CMakeLists.txt` file:

{% code title="CMakeLists.txt" overflow="wrap" lineNumbers="true" %}
```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)
```
{% endcode %}

3. Build and run the project:

{% code title="bash" overflow="wrap" %}
```bash
mkdir build
cd build
cmake ..
cmake --build .
./HelloWorld
```
{% endcode %}

4. Output:

{% code overflow="wrap" %}
```
Hello, World!
```
{% endcode %}

## Quiz

<details>

<summary>What is the purpose of cmake_minimum_required?</summary>

The purpose of `cmake_minimum_required` is to specify the minimum CMake version required to compile. If the current version is lower, it will throw an error.

</details>

<details>

<summary>What does <code>add_executable</code> do?</summary>

`add_executable` specifies the target executable name and associated source files.

</details>

<details>

<summary>Why do we create a <code>build</code> directory?</summary>

We create a `build` directory to separate the source from the build files.

</details>

