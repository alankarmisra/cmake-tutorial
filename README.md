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

When working on small C++ projects with just one or two files, compiling manually using `g++` or `clang++` is simple. However, as projects grow and include multiple source files, dependencies, and libraries, managing the build process manually becomes tedious and error-prone. This is where `Make` comes in.

## Manual Compilation

Consider a simple project structure with the following files:

```bash
project/
├── P.cxx    # Main program
├── A.cxx    # Module A
├── A1.cxx   # Sub-module A1
├── A2.cxx   # Sub-module A2
├── B.cxx    # Module B
├── B1.cxx   # Sub-module B1
├── B2.cxx   # Sub-module B2
```

Each module depends on its submodules. The main program `P.cxx` depends on `A.cxx` and `B.cxx`, which in turn depend on their respective submodules.

A possible manual compilation process might look like this:

```bash
g++ -c A1.cxx -o A1.o
g++ -c A2.cxx -o A2.o
g++ -c A.cxx -o A.o
g++ -c B1.cxx -o B1.o
g++ -c B2.cxx -o B2.o
g++ -c B.cxx -o B.o
g++ -c P.cxx -o P.o
g++ P.o A.o A1.o A2.o B.o B1.o B2.o -o program
```

## Problems with Manual Compilation

1. **Time-Consuming**: Manually typing out compilation commands is inefficient.
2. **Error-Prone**: Forgetting a dependency can result in linker errors.
3. **Unnecessary Recompilation**: Even if only `A1.cxx` changes, recompiling everything wastes time.
4. **Platform-Specific**: The compilation process might differ for different operating systems.

## Introducing Make

`Make` is a tool that automates the compilation process. It uses a `Makefile` to define rules for compiling and linking source files. A simple `Makefile` for our project might look like this:

```make
program: P.o A.o A1.o A2.o B.o B1.o B2.o
	g++ P.o A.o A1.o A2.o B.o B1.o B2.o -o program

P.o: P.cxx
	g++ -c P.cxx -o P.o

A.o: A.cxx A1.o A2.o
	g++ -c A.cxx -o A.o

A1.o: A1.cxx
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

With this `Makefile`, instead of typing out long compilation commands, you can simply run:

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

<summary>What does <code>make</code> do when you run <code>make</code> in a directory with a <code>Makefile</code>?</summary>

`Make` reads the `Makefile` and executes the compilation commands necessary to build the program.

</details>

<details>

<summary>How does <code>Make</code> help with unnecessary recompilation?</summary>

`Make` only recompiles files that have changed, avoiding unnecessary recompilation.

</details>
