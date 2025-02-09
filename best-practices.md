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

# Best Practices

## Introduction

Writing clean and maintainable CMake code is essential for large projects. In this lesson, we’ll cover:

* **Modular CMake**: Organize your project into modules.
* **Target-Based Design**: Use targets instead of global variables.
* **Versioning**: Specify minimum CMake versions and project versions.

## Key Concepts

* **Modular CMake**: Break your project into smaller, reusable modules.
* **Target-Based Design**: Use targets to manage dependencies and properties.
* **Versioning**: Use `project(MyProject VERSION 1.0.0)` to specify project versions.

## Code Sample

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0.0)

add_subdirectory(src)
add_subdirectory(lib)
```

## Quiz

<details>

<summary>Why is modular <code>CMake</code> important?</summary>

Modular `CMake` makes your project easier to maintain and scale.

</details>

<details>

<summary>What is the benefit of using target-based design?</summary>

Target-based design avoids global variables and makes dependencies explicit.

</details>

<details>

<summary>How do you specify a project version in <code>CMake</code>?</summary>

You specify a project version using `project(MyProject VERSION 1.0.0)`.

</details>
