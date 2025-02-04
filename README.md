# CMake Tutorial Series

---

## Chapter 1: Introduction to CMake

### Chapter Contents
CMake is a build system generator that allows you to create build scripts (like Makefiles, Visual Studio projects, etc.) in a platform-independent way. It helps manage the build process for C/C++ projects.

#### Key Concepts
- **CMakeLists.txt**: The main configuration file for CMake.
- **`cmake` command**: Used to generate build files.
- **`make` command**: Used to compile the project (on Unix-like systems).
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

---

## Chapter 2: Variables and Options

### Chapter Contents
CMake allows you to define variables and options to control the build process. Variables can store paths, flags, or other values, while options are boolean values that can be toggled on or off.

#### Key Concepts
- **`set()`**: Assigns a value to a variable.
- **`option()`**: Defines a boolean option that can be toggled on or off.
- **`if()`**: Used to conditionally execute CMake code.

#### Code Sample

1. Continue using the files from the previous chapter. Edit the `CMakeLists.txt` file to define a variable and use it:
```cmake
# CMakeLists.txt
set(MY_VARIABLE "Hello, CMake!")
message(STATUS "MY_VARIABLE is set to ${MY_VARIABLE}")
```

2. Define an option:
```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

# --- ADD THESE LINES ---
set(MY_VARIABLE "Hello, CMake!")
message(STATUS "MY_VARIABLE is set to ${MY_VARIABLE}")

option(ENABLE_FEATURE "Enable a feature" ON)
if(ENABLE_FEATURE)
    message(STATUS "Feature is enabled")
else()
    message(STATUS "Feature is disabled")
endif()
```

3. Build the project:
```bash
$ cmake ..
```
You should see the status messages printed out on the terminal.
```bash
-- MY_VARIABLE is set to Hello, CMake!
-- Feature is enabled
-- Configuring done (0.1s)
-- Generating done (0.0s)
...
```

4. Build the project again with the ENABLE_FEATURE turned off.
```bash
cmake .. -DENABLE_FEATURE=off
```
You should see the status messages printed out on the terminal.
```bash
-- MY_VARIABLE is set to Hello, CMake!
-- Feature is disabled
-- Configuring done (0.1s)
-- Generating done (0.0s)
```

### Quiz
1. What does the `set` command do?
2. How do you check if an option is enabled?
3. What is the difference between `set` and `option`?

### Answers
1. The `set` command assigns a value to a variable. This value can be a string, a path, a list, or even a complex expression.
2. You can check if an option is enabled using `if(OPTION_NAME)`.
3. `set` is for general-purpose variables (strings, paths, etc.), while `option` is specifically for boolean flags (`ON` or `OFF`) that can be toggled by the user.

---

## Chapter 3: Adding Libraries

### Chapter Contents
CMake makes it easy to link libraries to your project. Libraries can be system libraries, third-party libraries, or libraries you build yourself.

#### Key Concepts
- **`find_package()`**: Finds a system library or package.
- **`add_library()`**: Creates a library target.
- **`target_link_libraries()`**: Links libraries to a target.

#### Code Sample
You can continue using the files from the previous chapter.

1. Create a new file my_library.cpp with some dummy code
```cpp
// my_library.cpp
void my_library_func() {
  // noop
}
```

2. Edit the `CMakeLists.txt`
```cmake
# CMakeLists.txt 
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

set(MY_VARIABLE "Hello, CMake!")
message(STATUS "MY_VARIABLE is set to ${MY_VARIABLE}")

option(ENABLE_FEATURE "Enable a feature" ON)
if(ENABLE_FEATURE)
    message(STATUS "Feature is enabled")
else()
    message(STATUS "Feature is disabled")
endif()

# --- ADD THESE LINES ---
find_package(Threads REQUIRED)
target_link_libraries(HelloWorld PRIVATE Threads::Threads)

add_library(MyLibrary STATIC my_library.cpp)
target_link_libraries(HelloWorld PRIVATE MyLibrary)
```

### Quiz
1. What does `find_package` do?
2. How do you create a static library in CMake?
3. What is the purpose of `target_link_libraries`?

### Answers
1. `find_package` locates a system library or package. If `REQUIRED` is specified and the package isn’t found, CMake will stop with an error.
2. You can create a static library using `add_library(MyLibrary STATIC ...)`.
3. `target_link_libraries` links the specified libraries to your executable or library target.

---

## Chapter 4: Conditional Builds

### Chapter Contents
CMake allows you to conditionally include or exclude parts of your build based on variables, options, or system properties.

#### Key Concepts
- **`if()`**: Used to conditionally execute CMake code.
- **`target_compile_definitions()`**: Adds compile definitions to a target.
- **`set()`**: Used to conditionally set variables.

#### Code Sample
1. Create `windows_specific.cpp` file with some dummy code.
```cpp
// windows_specific.cpp
void windows_function() {}
```

2. Create `unix_specific.cpp` file with some dummy code.
```cpp
// unix_specific.cpp
void unix_function() {}
```

3. Edit the CMakeListsFile.txt to include the extra sources and add them to the executable.
```cmake
# CMakeListsFile.txt 
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# --- ADD THESE LINES ---
if(WIN32)
    message(STATUS "Including windows_specific.cpp")
    set(EXTRA_SOURCES windows_specific.cpp)
else()
    message(STATUS "Including unix_specific.cpp")
    set(EXTRA_SOURCES unix_specific.cpp)
endif()
# -----------------------

# --- EDIT THIS LINE TO INCLUDE ${EXTRA_SOURCES} ---
add_executable(HelloWorld main.cpp ${EXTRA_SOURCES})
# --------------------------------------------------

set(MY_VARIABLE "Hello, CMake!")
message(STATUS "MY_VARIABLE is set to ${MY_VARIABLE}")

option(ENABLE_FEATURE "Enable a feature" ON)
if(ENABLE_FEATURE)
    message(STATUS "Feature is enabled")
else()
    message(STATUS "Feature is disabled")
endif()

find_package(Threads REQUIRED)
target_link_libraries(HelloWorld PRIVATE Threads::Threads)

add_library(MyLibrary STATIC my_library.cpp)
target_link_libraries(HelloWorld PRIVATE MyLibrary)
```

### Quiz
1. How do you check the operating system in CMake?
2. What does `target_compile_definitions` do?
3. Can you use `if` statements to control which files are compiled?

### Answers
1. You can check the operating system using `if(WIN32)`, `if(APPLE)`, or `if(UNIX)`.
2. `target_compile_definitions` adds compile definitions to a target. These definitions can be conditional using generator expressions.
3. Yes, you can use `if` statements to control which files are compiled by conditionally adding them to `add_executable` or `add_library`.

---

## Chapter 5: External Projects

### Chapter Contents
Sometimes, your project depends on external libraries or tools that aren’t part of your codebase. CMake provides two main ways to handle this:
1. **`ExternalProject_Add`**: Downloads, builds, and integrates an external project during the build process.
2. **`FetchContent`**: Fetches and integrates external projects at configure time (introduced in CMake 3.11).

#### Key Concepts
- **`FetchContent_Declare()`**: Declares an external project (e.g., a GitHub repository).
- **`FetchContent_MakeAvailable()`**: Downloads and makes the project available for use.
- **Integration**: The external project’s targets can be used in your `CMakeLists.txt` as if they were part of your project.

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

---

## Chapter 6: Custom Commands and Targets

### Chapter Contents
CMake allows you to define **custom commands** and **custom targets** to perform tasks that aren’t part of the standard build process. For example:
- Generating source files from a script.
- Running a code formatter or linter.
- Copying files or running post-build steps.

#### Key Concepts
- **`add_custom_command()`**: Defines a command to run at a specific stage of the build (e.g., before or after building a target).
- **`add_custom_target()`**: Creates a new target that can be invoked manually (e.g., `make my_target`) and can depend on other targets or commands.
- **`OUTPUT` and `DEPENDS`**: Used to specify files generated by the command and dependencies for the command.

#### Code Sample
1. Let's start by creating `makehello.cpp` which will generate a simple function for us. 
```cpp
// makehello.cpp
// This will generate a single function called sayHello()
// which prints Hello, World! to the stdin.
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  // make sure we have enough arguments
  if (argc < 2) {
    return 1;
  }

  std::ofstream fout(argv[1], std::ios_base::out);
  const bool fileOpen = fout.is_open();
  if (fileOpen) {
    fout << "#include <iostream>" << std::endl << std::endl;
    fout << "void sayHello() {" << std::endl;
    fout << "  std::cout << \"Hello, World!\" << std::endl;" << std::endl;
    fout << "};" << std::endl;
    fout.close();
  }
  return fileOpen ? 0 : 1; // return 0 if wrote the file
}
```

2. Let's create a `makehello.cmake` file which will create a `MakeHello` executable from makehello.cpp and run it using the custom command feature to finally generate our `hello.h` file.
```cmake
# makehello.cmake
add_executable(MakeHello makehello.cpp)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/hello.h
  COMMAND MakeHello ${CMAKE_CURRENT_BINARY_DIR}/hello.h
  DEPENDS MakeHello
  )
```
Notice above how  `OUTPUT` specifies that `hello.h` will be generated in the bin directory (called `build` in our case). This helps CMake decide when to run this custom command - i.e. whenever something references `hello.h`  

3. Let's edit the `main.cpp` file to call the `sayHello`  function which will be defined in `hello.h` when it is generated. Your editor will indicate that `hello.h` is missing for now.
```cpp
#include "hello.h" 
#include <iostream>

int main() {
  sayHello();
  return 0;
}
```
4. Finally, let's edit the CMakeLists.txt file to include the makehello.cmake file. 
```cmake
cmake_minimum_required(VERSION 3.15)
project(HelloWorld)

# Include the custom command.
include(makehello.cmake)

# We add the dependency to hello.h
# This will automatically run our custom command.
add_executable(HelloWorld main.cpp ${CMAKE_CURRENT_BINARY_DIR}/hello.h)

# Since hello.h is generated in the build/bin directory
# we need to add it to the list of directories
# that will be looked at for header files
target_include_directories(HelloWorld PRIVATE
                             ${CMAKE_CURRENT_BINARY_DIR}
                             )
```
5. Run cmake and build. 
```bash
cmake ..
cmake --build .
```
You should find `hello.h` in the `build` directory and everything should compile nicely.

6. Run the binary and observe the output
```bash
./HelloWorld
Hello, World!
```

### Quiz
1. What is the purpose of `add_custom_command`?
2. What does the `OUTPUT` argument specify in `add_custom_command`?
3. How is `add_custom_target` different from `add_custom_command`?

### Answers
1. `add_custom_command` defines a command to run during the build process, such as generating files or running scripts.
2. The `OUTPUT` argument specifies the file(s) generated by the custom command.
3. `add_custom_command` defines a command tied to specific outputs, while `add_custom_target` creates a named target that can be manually invoked or included in the default build.

---

## Chapter 7: Advanced Custom Commands

### Chapter Contents
Custom commands can be tied to specific build events, such as **pre-build** or **post-build** steps. This allows you to automate tasks like:
- Running a code formatter before building.
- Copying files or running tests after building.
- Generating files dynamically based on build configurations.

#### Key Concepts
- **`PRE_BUILD`, `PRE_LINK`, and `POST_BUILD`**: These options tie custom commands to specific stages of the build process.
- **Generator Expressions**: Special CMake syntax (e.g., `$<CONFIG:Debug>`) that evaluates at build time.
- **Combining Commands**: Use multiple `add_custom_command` calls to create complex workflows.

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

---

## Chapter 8: Testing with CTest

### Chapter Contents
CTest is a testing tool that comes bundled with CMake. It allows you to:
- Define tests in your `CMakeLists.txt`.
- Run tests and generate reports.
- Integrate with testing frameworks like GoogleTest.

#### Key Concepts
- **`enable_testing()`**: Enables testing for the project.
- **`add_test()`**: Defines a test.
- **`ctest`**: The command-line tool to run tests.

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
1. What does `enable_testing()` do?
2. How do you define a test using `add_test()`?
3. What is the purpose of `ctest`?

### Answers
1. `enable_testing()` enables testing support in your project.
2. You define a test using `add_test(NAME TestName COMMAND TestCommand)`.
3. `ctest` runs all the tests defined in your project and generates reports.

---

## Chapter 9: Packaging with CPack

### Chapter Contents
CPack is a tool that comes bundled with CMake. It allows you to create platform-specific packages for your project, such as:
- **`.dmg`**: Disk Image (common on macOS).
- **`.tar.gz`**: Compressed archive (common on Unix-like systems).
- **`.zip`**: Compressed archive (common on Windows).

#### Key Concepts
- **`install()`**: Specifies files or targets to include in the package.
- **`include(CPack)`**: Enables CPack and generates packaging targets.
- **CPack Generators**: Specify the type of package to create (e.g., `DragNDrop` for `.dmg`).

#### Code Sample
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

### Quiz
1. What does the `install()` command do?
2. How do you specify the type of package to create with CPack?
3. What is the purpose of `include(CPack)`?

### Answers
1. The `install()` command specifies which files or targets should be included in the package and where they should be installed.
2. You specify the type of package using the `CPACK_GENERATOR` variable (e.g., `DragNDrop` for `.dmg`).
3. `include(CPack)` enables CPack and generates the necessary packaging targets.

---

## Chapter 10: Advanced CPack Customization

### Chapter Contents
CPack is highly customizable, allowing you to tailor your packages to specific needs. In this lesson, we’ll cover:
- Adding metadata (e.g., version, description, vendor).
- Including additional files (e.g., licenses, READMEs).
- Creating platform-specific installers (e.g., `.pkg` for macOS).

#### Key Concepts
- **CPack Metadata**: Customize package information like name, version, and description.
- **Including Files**: Add extra files (e.g., licenses, READMEs) to your package.
- **Platform-Specific Installers**: Use generators like `PackageMaker` for macOS `.pkg` files.

1. Update your `CMakeLists.txt`:
#### Code Sample
```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

install(TARGETS HelloWorld DESTINATION bin)

set(CPACK_PACKAGE_NAME "HelloWorld")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "A simple program packaged with CPack")
# ---- Add this ------
set(CPACK_PACKAGE_VENDOR "MyCompany")
set(CPACK_PACKAGE_CONTACT "support@mycompany.com")

# This displays the `LICENSE.txt` text in a License agreement box when you double-click the `dmg` but doesn't include the actual file in the package.
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")

# install() will add the files to the package
install(FILES ${CMAKE_SOURCE_DIR}/LICENSE.txt DESTINATION .)
install(FILES ${CMAKE_SOURCE_DIR}/README.md DESTINATION .)

# ---------------------
set(CPACK_GENERATOR "DragNDrop;TGZ")
include(CPack)
```
2. Create a `LICENSE.txt` file:
```
MIT License

Copyright (c) 2023 MyCompany

Permission is hereby granted...
```
3. Create a `README.md` file:
```markdown
# MyProgram

This is a simple program packaged with CPack.
```
4. Build and package the product:
```bash
mkdir build
cd build
cmake ..
make
cpack
```
If you open the .dmg file it will show you the contents of the `LICENSE.txt` file and ask you to agree. The `.dmg` and `.tar.gz` packages will now include the `LICENSE.txt` and `README.md` files.

### Quiz
1. What is the purpose of `CPACK_RESOURCE_FILE_LICENSE`?
2. How do you specify the generator for a macOS `.pkg` installer?
3. What does `CPACK_PACKAGE_VENDOR` do?

### Answers
1. `CPACK_RESOURCE_FILE_LICENSE` specifies the license file to include in the package.
2. You specify the generator for a macOS `.pkg` installer using `set(CPACK_GENERATOR "PackageMaker")`.
3. `CPACK_PACKAGE_VENDOR` specifies the vendor name for the package.

---

## Chapter 11: Advanced CMake Features

### Chapter Contents
CMake has several advanced features that can make your build system more powerful and flexible. In this lesson, we’ll cover:
- **Generator Expressions**: Dynamic expressions evaluated at build time.
- **Toolchain Files**: Customize the build for different compilers or platforms.
- **Exporting and Importing Targets**: Share targets between projects.

#### Key Concepts
- **Generator Expressions**: Allow you to write dynamic CMake code that adapts to the build configuration.
- **Toolchain Files**: Specify compilers, flags, and paths for cross-platform development.
- **Exporting Targets**: Share targets between projects using `export()` and `install(EXPORT)`.

#### Code Sample
```cmake
cmake_minimum_required(VERSION 3.10)
project(GeneratorExpressionsDemo)

add_executable(MyProgram main.cpp)

target_compile_definitions(MyProgram PRIVATE
    $<$<CONFIG:Debug>:DEBUG_MODE>
)

target_compile_options(MyProgram PRIVATE
    $<$<CONFIG:Debug>:-O0>
)
```

### Quiz
1. What is the purpose of generator expressions?
2. How do you conditionally add a compiler flag for Debug builds?
3. What does `$<CONFIG:Debug>` evaluate to in Release mode?

### Answers
1. Generator expressions allow you to write dynamic CMake code that adapts to the build configuration.
2. You can conditionally add a compiler flag using `target_compile_options(MyTarget PRIVATE $<$<CONFIG:Debug>:-O0>)`.
3. `$<CONFIG:Debug>` evaluates to `0` (false) in Release mode.

---

## Chapter 12: Best Practices

### Chapter Contents
Writing clean and maintainable CMake code is essential for large projects. In this lesson, we’ll cover:
- **Modular CMake**: Organize your project into modules.
- **Target-Based Design**: Use targets instead of global variables.
- **Versioning**: Specify minimum CMake versions and project versions.

#### Key Concepts
- **Modular CMake**: Break your project into smaller, reusable modules.
- **Target-Based Design**: Use targets to manage dependencies and properties.
- **Versioning**: Use `project(MyProject VERSION 1.0.0)` to specify project versions.

#### Code Sample
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0.0)

add_subdirectory(src)
add_subdirectory(lib)
```

### Quiz
1. Why is modular CMake important?
2. What is the benefit of using target-based design?
3. How do you specify a project version in CMake?

### Answers
1. Modular CMake makes your project easier to maintain and scale.
2. Target-based design avoids global variables and makes dependencies explicit.
3. You specify a project version using `project(MyProject VERSION 1.0.0)`.

---

## Chapter 13: Cross-Platform Development

### Chapter Contents
CMake makes it easy to write cross-platform build systems. In this lesson, we’ll cover:
- **Platform Detection**: Detect the operating system and compiler.
- **Conditional Compilation**: Use platform-specific code.
- **Toolchain Files**: Customize the build for different platforms.

#### Key Concepts
- **Platform Detection**: Use `if(WIN32)`, `if(APPLE)`, or `if(UNIX)` to detect the operating system.
- **Conditional Compilation**: Use `#ifdef` in your source code or generator expressions in CMake.
- **Toolchain Files**: Specify compilers, flags, and paths for cross-platform development.

#### Code Sample
```cmake
cmake_minimum_required(VERSION 3.10)
project(CrossPlatformDemo)

if(WIN32)
    message(STATUS "Building on Windows")
elseif(APPLE)
    message(STATUS "Building on macOS")
elseif(UNIX)
    message(STATUS "Building on Unix")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GCC")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Using Clang")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Using MSVC")
endif()

add_executable(MyProgram main.cpp)
```

### Quiz
1. How do you detect the operating system in CMake?
2. What is the purpose of `CMAKE_CXX_COMPILER_ID`?
3. How can you use toolchain files for cross-platform development?

### Answers
1. You detect the operating system using `if(WIN32)`, `if(APPLE)`, or `if(UNIX)`.
2. `CMAKE_CXX_COMPILER_ID` identifies the compiler being used (e.g., GCC, Clang, MSVC).
3. Toolchain files allow you to customize the build for different platforms by specifying compilers, flags, and paths.

---
