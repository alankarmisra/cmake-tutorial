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

# Advanced CPack Customization

CPack is highly customizable, allowing you to tailor your packages to specific needs. In this lesson, we’ll cover:

* Adding metadata (e.g., version, description, vendor).
* Including additional files (e.g., licenses, READMEs).
* Creating platform-specific installers (e.g., `.pkg` for macOS).

#### Key Concepts

* **CPack Metadata**: Customize package information like name, version, and description.
* **Including Files**: Add extra files (e.g., licenses, READMEs) to your package.
* **Platform-Specific Installers**: Use generators like `PackageMaker` for macOS `.pkg` files.

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

<details>

<summary>What is the purpose of <code>CPACK_RESOURCE_FILE_LICENSE</code>?</summary>

`CPACK_RESOURCE_FILE_LICENSE` specifies the license file to include in the package.

</details>

<details>

<summary>How do you specify the generator for a macOS <code>.pkg</code> installer?</summary>

You specify the generator for a macOS `.pkg` installer using `set(CPACK_GENERATOR "PackageMaker")`.

</details>

<details>

<summary>What does <code>CPACK_PACKAGE_VENDOR</code> do?</summary>

`CPACK_PACKAGE_VENDOR` specifies the vendor name for the package.

</details>
