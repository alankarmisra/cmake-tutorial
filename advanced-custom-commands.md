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

# Advanced Custom Commands

Custom commands can be tied to specific build events, such as **pre-build** or **post-build** steps. This allows you to automate tasks like:

* Running a code formatter before building.
* Copying files or running tests after building.
* Generating files dynamically based on build configurations.

#### Key Concepts

* **`PRE_BUILD`, `PRE_LINK`, and `POST_BUILD`**: These options tie custom commands to specific stages of the build process.
* **Generator Expressions**: Special CMake syntax (e.g., `$<CONFIG:Debug>`) that evaluates at build time.
* **Combining Commands**: Use multiple `add_custom_command` calls to create complex workflows.

#### Code Sample

1. We will start with the `main.cpp` file and the `CMakeLists.txt` file from `Chapter 1`.

```cpp
#include <iostream>
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
```

2. In addition to the standard lines for compilations, add a few lines to `CMakeLists.txt` to run a command after the build completes.

```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

# ----- Add this -----
# We want to run 
# `cmake -E echo "Build succeeded!"`
# after the build
add_custom_command(
    TARGET HelloWorld POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Build succeeded!"
    COMMENT "Running post-build step"
)
```

3. Run cmake and build, and observe the output

```bash
cmake ..
cmake --build .
```

4. Observe the output

```bash
...
Running post-build step
Build succeeded!
```

### Quiz

1. What is the purpose of the `POST_BUILD` option in `add_custom_command`?
2. How do generator expressions (e.g., `$<CONFIG>`) work?
3. Can you combine multiple custom commands into a single workflow?

### Answers

1. The `POST_BUILD` option specifies that the command should run after the target is built.
2. Generator expressions are evaluated at build time and allow you to write dynamic CMake code.
3. Yes, you can combine multiple `add_custom_command` calls to create complex workflows.
