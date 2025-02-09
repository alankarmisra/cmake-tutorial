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

# Variables and Options

CMake allows you to define variables and options to control the build process. Variables can store paths, flags, or other values, while options are boolean values that can be toggled on or off.

## **Key Concepts**

* **`set()`**: Assigns a value to a variable.
* **`option()`**: Defines a boolean option that can be toggled on or off.
* **`if()`**: Used to conditionally execute CMake code.

## **Code Sample**

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

4. Build the project again with the ENABLE\_FEATURE turned off.

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

## Quiz

<details>

<summary>What does the <code>set</code> command do?</summary>

The `set` command assigns a value to a variable. This value can be a string, a path, a list, or even a complex expression.

</details>

<details>

<summary>How do you check if an option is enabled?</summary>

You can check if an option is enabled using `if(OPTION_NAME)`.

</details>

<details>

<summary>What is the difference between <code>set</code> and <code>option</code>?</summary>

`set` is for general-purpose variables (strings, paths, etc.), while `option` is specifically for boolean flags (`ON` or `OFF`) that can be toggled by the user.

</details>
