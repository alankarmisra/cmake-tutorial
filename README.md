# Introduction to CMake

CMake is a build system generator that allows you to create build scripts (like Makefiles, Visual Studio projects, etc.) in a platform-independent way. It helps manage the build process for C/C++ projects.

#### Key Concepts

* **CMakeLists.txt**: The main configuration file for CMake.
* **`cmake` command**: Used to generate build files.
* **`make` command**: Used to compile the project (on Unix-like systems).

#### Code Sample

1. Create a file `main.cpp`:

```cpp
// main.cpp
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

2. Create a `CMakeLists.txt` file:

```cmake
# CMakeLists.txt
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

4. Review the output

```bash
Hello, World!
```

### Quiz

1. What is the purpose of `cmake_minimum_required`?
2. What does `add_executable` do?
3. Why do we create a `build` directory?

### Answers

1. The purpose of `cmake_minimum_required` is to specify the minimum CMake version required to compile. If the current version is lower, it will throw an error.
2. `add_executable` specifies the target executable name and associated source files.
3. We create a `build` directory to separate the source from the build files.

