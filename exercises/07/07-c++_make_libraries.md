<!--
title: Exercise session 07
paginate: true

_class: titlepage
-->

# Exercise session 07
<br>

## Introduction to GNU Make. Libraries: building and use.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 16 Nov 2023

---

<!--
_class: titlepage
-->

# Introduction to GNU Make

---

# Introduction

### Prerequisites

Ensure the `make` program is installed by checking `make -version`. If not installed, use package managers such as `apt` on Unix or [`Homebrew`](https://formulae.brew.sh/formula/make) on macOS. Additionally, have a C++ compiler like `g++` or `clang++` ready for compilation.

---

# Getting Started

Let's start with a simple C++ program consisting of three files: 
- `math.hpp`
- `math.cpp`
- `main.cpp`

#### Manual compilation

```bash
g++ -c -I. -std=c++17 -Wall -Wpedantic -Werror main.cpp math.cpp
g++ -Wall -Wpedantic -Werror main.o math.o -o main

# Alternatively, in a single line:
g++ -I. -Wall -Wpedantic -Werror main.cpp math.cpp -o main
```

This process involves creating object files and linking them to generate the executable. Now, let's simplify this with a Makefile.

---

# Definitions

- In a Makefile, a **target** represents the desired output or action. It can be an executable, an object file, or a specific action like "clean."

- **Prerequisites** are files or conditions that a target depends on. If any of the prerequisites have been modified more recently than the target, or if the target does not exist, the associated recipe is executed.

- A **recipe** is a set of shell commands that are executed to build or update the target. Recipes follow the prerequisites and are indented with a **tab character**. Each line in the recipe typically represents a separate command.

---

# Creating a basic Makefile for C++

Putting it all together:

```make
main: main.cpp math.cpp
	g++ -I. -Wall -Wpedantic -Werror main.cpp math.cpp -o main
```

- **Target (`main`):** The executable we want to create.
- **Prerequisites (`main.cpp math.cpp`):** The source files required to build the target.
- **Recipe (`g++ [...] main.cpp math.cpp -o main`):** The shell command to compile (`g++`) and link (`-o main`) the source files into the executable (`main`).

---

# Variables for clarity

Enhance readability and maintainability by using variables:

```make
CXX=g++
CPPFLAGS=-I.
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror

main: main.cpp math.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) main.cpp math.cpp -o main
```

- **CXX:** Compiler variable.
- **CPPFLAGS:** Preprocessor flags variable.
- **CXXFLAGS:** Compiler flags variable.

---

# Automatic dependency generation

```make
CXX=g++
CPPFLAGS=-I.
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror
DEPS=math.hpp

%.o: %.cpp $(DEPS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

main: main.o math.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm *.o main
```

- `%.o:` A generic rule for creating files with `.o` extension.
- `$@`, `$<`, `$^`: Automatic variables representing the target, the first prerequisite, and all prerequisites, respectively.

---

# Phony targets

Define phony targets for non-file related tasks:

```make
.PHONY: all clean

all: main

main: main.o math.o
	$(CXX) $(CXXFLAGS) $^ -o $<

clean:
	rm *.o main
```

- **.PHONY:** Marks targets that don't represent files.
- **all:** Default target.

---

# Variables for source files

```make
CXX=g++
CPPFLAGS=-I.
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror
DEPS=math.hpp
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

.PHONY: all clean

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(DEPS)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm *.o main
```

---

# Building a library and linking against it

Suppose we have a simple C++ library with two files
- `math.hpp`
- `math.cpp`

Additionally, we have a program, `main.cpp`, that uses functions from this library.

Now, let's create a Makefile to build the library and another one to link our program against it.

---

# Makefile to build a library (1/2)

```make
CXX=g++
CPPFLAGS=-I.
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror

SRC=math.cpp
OBJ=$(SRC:.cpp=.o)
OBJ_fPIC=$(SRC:.cpp=.shared.o)
DEPS=math.hpp

LIB_NAME_STATIC=libmath.a
LIB_NAME_SHARED=libmath.so

all: static shared

static: $(LIB_NAME_STATIC)
shared: $(LIB_NAME_SHARED)
```

---

# Makefile to build a library (2/2)

```
$(LIB_NAME_STATIC): $(OBJ)
	ar rcs $@ $^

$(LIB_NAME_SHARED): $(OBJ_fPIC)
	g++ $(CXXFLAGS) -shared $^ -o $@

%.shared.o: %.cpp $(DEPS)
	$(CXX) -c -fPIC $(CPPFLAGS) $(CXXFLAGS) $< -o $@

%.o: %.cpp $(DEPS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(LIB_NAME_STATIC) $(LIB_NAME_SHARED)
```

---

# Makefile to link against a library

```make
CXX=g++
CPPFLAGS=-Imath/
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror
LDFLAGS=-Wl,-rpath,math/ -Lmath/ # For dynamic linking.
# LDFLAGS=-Lmath/ -static        # For static linking.
LDLIBS=-lmath

SRC=main.cpp
OBJ=$(SRC:.cpp=.o)

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o main
```

---

What's good about makefile

    The make program checks whether target exists and if the prerequisite files of the target are up to date; if so, it avoids generating the target again
    A lot of libraries can be installed with few commands using make as tool. A common pattern to install an open source library could be the following:

make 
make install

Generally the make command build the library and the make install copy the headers of the library into /usr/include (or /usr/local/include), the dynamic libraries .so or static libraries .a into usr/lib (or /usr/local/lib) and the binaries into usr/bin (or /usr/local/bin). In that way after the installation of the library you can use it for example in your source code.

Sometimes you can also see make -jN which run N jobs (commands) in parallel at the same time speeding up the build process.
What's not good about makefile

    Makefiles are O.S. dependent so you need to adapt them to different systems. Take a look to CMake as a possible solution to solve this problem.
    Each command of each recipe must start with a tab space and that could be a real no-sense source of errors.


# References

Dive deeper into Makefiles with these resources:

- [A simple makefile tutorial](https://cs.colby.edu/maxwell/courses/tutorials/maketutor/): Essential tutorial on make and Makefile.
- [GNU make](https://www.gnu.org/software/make/manual/make.html): Official documentation for make and Makefile.
- [Makefile tutorial](https://github.com/vampy/Makefile): A GitHub repository with numerous makefile examples.

---

# Exercise 1: building and using `muParserX`

- Download and extract [`muParserX`](https://beltoforion.de/en/muparserx/):
  ```bash
  wget https://github.com/beltoforion/muparserx/archive/refs/tags/v4.0.12.tar.gz
  ```
- The source files of `muParserX` are located inside the `muparserx-4.0.12/parser/` folder.
- In that folder, write a `Makefile` to compile `muParserX` into a shared library.
- Write a Makefile that compiles and links the program in `hints/ex1.cpp` with `muParserX`.

---

# Exercise 2:

---

# Exercise 3: dynamic loading



`-ldl`
