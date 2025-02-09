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

# Testing with CTest

CTest is a testing tool that comes bundled with CMake. It allows you to:

* Define tests in your `CMakeLists.txt`.
* Run tests and generate reports.
* Integrate with testing frameworks like GoogleTest.

#### Key Concepts

* **`enable_testing()`**: Enables testing for the project.
* **`add_test()`**: Defines a test.
* **`ctest`**: The command-line tool to run tests.

#### Code Sample

1. Create `CMakeLists.txt` or copy it from `Chapter 1` and add the lines to enable testing:

```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

# ---- Add this ------
# Enable testing
enable_testing()
# Notice, we don't have any explicit tests yet. We only make sure that the program runs without errors.
add_test(NAME HelloWorldTest COMMAND HelloWorld)
# --------------------
```

2. Write `main.cpp` or copy it from `Chapter 1`

```cpp
#include <iostream>
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
```

3. Build and run the tests:

```bash
mkdir build
cd build
cmake ..
cmake --build .
ctest
```

Output:

```bash
Test project /path/to/build
    Start 1: HelloWorldTest
1/1 Test #1: HelloWorldTest ...................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1
```

#### Code Sample : Advanced Tests with GoogleTest

Now let’s integrate GoogleTest for more sophisticated testing.

1. Update your `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# ---- Add this ------
# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
# --------------------

add_executable(HelloWorld main.cpp)

# Add a test executable
add_executable(HelloWorldTest test.cpp)

# ---- Add this ------
# Link the google test library with our test executable
target_link_libraries(HelloWorldTest PRIVATE gtest_main)
# --------------------

# Enable testing
enable_testing()
add_test(NAME HelloWorldTest COMMAND HelloWorldTest)

```

2. Write `test.cpp`

```cpp
#include <gtest/gtest.h>

TEST(MyTestSuite, MyTestCase) {
    EXPECT_EQ(1 + 1, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

3. Build and run the tests

```bash
mkdir build
cd build
cmake ..
make
ctest
```

Output:

```bash
Test project /path/to/build
    Start 1: HelloWorldTest
1/1 Test #1: HelloWorldTest .........................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec
```

### Quiz

<details>

<summary>What does <code>enable_testing()</code> do?</summary>

`enable_testing()` enables testing support in your project.

</details>

<details>

<summary>How do you define a test using <code>add_test()</code>?</summary>

You define a test using `add_test(NAME TestName COMMAND TestCommand)`.

</details>

<details>

<summary>What is the purpose of <code>ctest</code>?</summary>

`ctest` runs all the tests defined in your project and generates reports.

</details>
