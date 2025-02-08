# Introduction to CMake

CMake is a build system generator that allows you to create build scripts (like Makefiles, Visual Studio projects, etc.) in a platform-independent way. It helps manage the build process for C/C++ projects.

#### Key Concepts

* **CMakeLists.txt**: The main configuration file for CMake.
* **`cmake` command**: Used to generate build files.
* **`make` command**: Used to compile the project (on Unix-like systems).

#### Code Sample

1. Create a file `main.cpp`:

{% code title="main.cpp" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```cfscript
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
```bash
Hello, World!
```
{% endcode %}

### Quiz

1. What is the purpose of `cmake_minimum_required`?
2. What does `add_executable` do?
3. Why do we create a `build` directory?

### Answers

1. The purpose of `cmake_minimum_required` is to specify the minimum CMake version required to compile. If the current version is lower, it will throw an error.
2. `add_executable` specifies the target executable name and associated source files.
3. We create a `build` directory to separate the source from the build files.

