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

Writing clean and maintainable CMake code is essential for large projects. In this lesson, we’ll cover:

* **Modular CMake**: Organize your project into modules.
* **Target-Based Design**: Use targets instead of global variables.
* **Versioning**: Specify minimum CMake versions and project versions.

#### Key Concepts

* **Modular CMake**: Break your project into smaller, reusable modules.
* **Target-Based Design**: Use targets to manage dependencies and properties.
* **Versioning**: Use `project(MyProject VERSION 1.0.0)` to specify project versions.

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
