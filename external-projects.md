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

# External Projects

Sometimes, your project depends on external libraries or tools that aren’t part of your codebase. CMake provides two main ways to handle this:

1. **`ExternalProject_Add`**: Downloads, builds, and integrates an external project during the build process.
2. **`FetchContent`**: Fetches and integrates external projects at configure time (introduced in CMake 3.11).

#### Key Concepts

* **`FetchContent_Declare()`**: Declares an external project (e.g., a GitHub repository).
* **`FetchContent_MakeAvailable()`**: Downloads and makes the project available for use.
* **Integration**: The external project’s targets can be used in your `CMakeLists.txt` as if they were part of your project.

#### Code Sample

1. Let's start with a fresh CMakeLists.txt file to keep things simple. You can continue using the files from the previous chapter, but replace the entire contents of the CMakeLists.txt to the one below.

```cmake
# CMakeLists.txt
# ---- Replace everything with the text below -----
cmake_minimum_required(VERSION 3.15)
project(HelloWorld)

include(FetchContent)
# This declares the googletest repo but does not download it.
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

# This downloads the googletest repo when you run `cmake ..`
FetchContent_MakeAvailable(googletest)

add_executable(HelloWorld main.cpp)
target_link_libraries(HelloWorld PRIVATE gtest_main)
```

2. Run cmake. This will download the googletest repo when it encounters `FetchContent_MakeAvailable`.

```cmake
cmake ..
```

3. Run the build

```cmake
cmake --build .
```

### Quiz

1. What is the purpose of `FetchContent_Declare`?
2. How do you make an external project available for use in your `CMakeLists.txt`?
3. What does `target_link_libraries` do when linking to an external project like GoogleTest?

### Answers

1. `FetchContent_Declare` declares an external project (e.g., a GitHub repository) and specifies how to fetch it.
2. You use `FetchContent_MakeAvailable` to download and make the external project available.
3. `target_link_libraries` links the external library to your target, making its functions available.
