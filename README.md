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
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

2. Create a `CMakeLists.txt` file:
```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)
```

3. Build the project:
```bash
mkdir build
cd build
cmake ..
make
./HelloWorld
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
```cmake
set(MY_VARIABLE "Hello, CMake!")
message(STATUS "MY_VARIABLE is set to ${MY_VARIABLE}")

option(ENABLE_FEATURE "Enable a feature" ON)
if(ENABLE_FEATURE)
    message(STATUS "Feature is enabled")
else()
    message(STATUS "Feature is disabled")
endif()
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
```cmake
find_package(Threads REQUIRED)
add_executable(MyProgram main.cpp)
target_link_libraries(MyProgram PRIVATE Threads::Threads)

add_library(MyLibrary STATIC my_library.cpp)
target_link_libraries(MyProgram PRIVATE MyLibrary)
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
```cmake
if(WIN32)
    set(EXTRA_SOURCES windows_specific.cpp)
else()
    set(EXTRA_SOURCES unix_specific.cpp)
endif()

add_executable(MyProgram main.cpp ${EXTRA_SOURCES})

if(ENABLE_FEATURE)
    target_compile_definitions(MyProgram PRIVATE USE_FEATURE)
endif()
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
```cmake
cmake_minimum_required(VERSION 3.14)
project(ExternalProjectDemo)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

add_executable(MyProgram main.cpp)
target_link_libraries(MyProgram PRIVATE gtest_main)
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
```cmake
cmake_minimum_required(VERSION 3.10)
project(CustomCommandDemo)

add_custom_command(
    OUTPUT generated.cpp
    COMMAND python3 ${CMAKE_SOURCE_DIR}/generate.py
    DEPENDS ${CMAKE_SOURCE_DIR}/generate.py
    COMMENT "Generating source file from script"
)

add_executable(MyProgram main.cpp generated.cpp)

add_custom_target(
    GenerateCode ALL
    DEPENDS generated.cpp
)
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
```cmake
cmake_minimum_required(VERSION 3.10)
project(AdvancedCustomCommandDemo)

add_executable(MyProgram main.cpp)

add_custom_command(
    TARGET MyProgram POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Build succeeded!"
    COMMENT "Running post-build step"
)
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
```cmake
cmake_minimum_required(VERSION 3.10)
project(TestingDemo)

enable_testing()

add_executable(MyProgram main.cpp)

add_test(NAME MyProgramTest COMMAND MyProgram)
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
```cmake
cmake_minimum_required(VERSION 3.10)
project(PackagingDemo)

add_executable(MyProgram main.cpp)

install(TARGETS MyProgram DESTINATION bin)

set(CPACK_PACKAGE_NAME "MyProgram")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "A simple program packaged with CPack")
set(CPACK_GENERATOR "DragNDrop;TGZ")
include(CPack)
```

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

#### Code Sample
```cmake
cmake_minimum_required(VERSION 3.10)
project(PackagingDemo)

add_executable(MyProgram main.cpp)

install(TARGETS MyProgram DESTINATION .)

set(CPACK_PACKAGE_NAME "MyProgram")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "A simple program packaged with CPack")
set(CPACK_PACKAGE_VENDOR "MyCompany")
set(CPACK_PACKAGE_CONTACT "support@mycompany.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")
set(CPACK_GENERATOR "DragNDrop;TGZ")
include(CPack)
```

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
