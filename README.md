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

# The problem Make solves

## Introduction

When working on small C++ projects with just one or two files, compiling manually using `g++` or `clang++` is simple. However, as projects grow and include multiple source files, dependencies, and libraries, managing the build process manually becomes tedious and error-prone. Let's look an example:

## Manual Compilation

Consider a simple project structure with the following files:

```sh
project/
├── P.cxx    # Main program
├── A.cxx    # Module A
├── A1.h     # Header for A1 (for brevity we've only mentioned one header)
├── A1.cxx   # Sub-module A1
├── A2.cxx   # Sub-module A2
├── B.cxx    # Module B
├── B1.cxx   # Sub-module B1
├── B2.cxx   # Sub-module B2
```

Each module depends on its submodules. The main program `P.cxx` depends on `A.cxx` and `B.cxx`, which in turn depend on their respective submodules.

A possible manual compilation process might look like this:

```sh
g++ -c A1.cxx -o A1.o
g++ -c A2.cxx -o A2.o
g++ -c A.cxx -o A.o
g++ -c B1.cxx -o B1.o
g++ -c B2.cxx -o B2.o
g++ -c B.cxx -o B.o
g++ -c P.cxx -o P.o
g++ P.o A.o A1.o A2.o B.o B1.o B2.o -o program
```

We don't like all that typing. If we were compiling the entire source tree, we could use wildcards to simplify the compilation and also run it in parallel.

```sh
find . -name "*.cxx" | parallel g++ -c {} -o {.}.o
g++ *.o -o program
```

Much better. But as we'll see soon, this is only pragmatic for small codebases.

## Problems with Manual Compilation

Say `A1.cxx` changes. We have a choice to recompile the entire codebase. As we've opined earlier, if we had a small codebase, this would be a reasonably pragmatic approach. On a large codebase, this will slow things down significantly. So we decide to track the dependencies ourselves. We recompile only `A1.cxx` and then link. This works too. As we begin to make changes across multiple files though, tracking dependencies manually starts to become cumbersome and error-prone rather quickly.

## Why Make?

* **Selective Compilation** – `make` uses timestamps to determine which files have changed, and only recompiles them and related dependecies as we illustrate next.
* **Dependency Management** – say you've declared a dependency of `A1.o` on `A1.cxx` and `A1.h`. If either `A1.cxx` or `A1.h` changes, `make` can detect this and recompile `A1.o`.
* **Modular Rules** – `make` allows defining rules for building individual components, making the build system more scalable.
* **Parallel Builds** – `make -j` enables parallel compilation, speeding up the process.

## The Makefile

`Make` uses a `Makefile` to define rules for compiling and linking source files. A  `Makefile` for our project might look like this:

```makefile
program: P.o A.o A1.o A2.o B.o B1.o B2.o
	g++ P.o A.o A1.o A2.o B.o B1.o B2.o -o program

P.o: P.cxx
	g++ -c P.cxx -o P.o

A.o: A.cxx A1.o A2.o
	g++ -c A.cxx -o A.o

A1.o: A1.cxx A1.h 
	g++ -c A1.cxx -o A1.o

A2.o: A2.cxx
	g++ -c A2.cxx -o A2.o

B.o: B.cxx B1.o B2.o
	g++ -c B.cxx -o B.o

B1.o: B1.cxx
	g++ -c B1.cxx -o B1.o

B2.o: B2.cxx
	g++ -c B2.cxx -o B2.o

clean:
	rm -f *.o program
```

## Running Make

With this `Makefile`, instead of typing out long compilation commands, we can simply run:

```bash
make
```

This will only recompile the necessary files when they change, saving time.

To clean up generated files, use:

```bash
make clean
```

## Limitations of Make

1. **Non-Portable**: Makefiles are often platform-dependent.
2. **Complexity**: Large projects require complex Makefiles.
3. **Lack of Built-in Dependency Management**: External dependencies must be manually handled.

## Transition to CMake

CMake is a more advanced build system generator that overcomes these limitations by generating platform-independent build scripts (including Makefiles). In the next chapter, we will introduce CMake and demonstrate how it simplifies build management.

## Quiz

<details>

<summary>What are the drawbacks of manually compiling a multi-file C++ project?</summary>

Manual compilation is time-consuming, error-prone, inefficient, and not scalable.

</details>

<details>

<summary>What does <code>make</code> do when we run <code>make</code> in a directory with a <code>Makefile</code>?</summary>

`Make` reads the `Makefile` and executes the compilation commands necessary to build the program.

</details>

<details>

<summary>How does <code>Make</code> help with unnecessary recompilation?</summary>

`Make` only recompiles files that have changed, avoiding unnecessary recompilation.

</details>
