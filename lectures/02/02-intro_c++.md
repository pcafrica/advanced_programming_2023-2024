<!--
title: Lecture 02
paginate: true

_class: titlepage
-->

# Lecture 02
<br>

## Introduction to C++. Built-in data types. Variables, pointers and references. Control structures. Functions.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa, Marco Feder

###### 03 Oct 2023

---

<!--
_class: green
-->

# Why C++?

C++ is:

- Reasonably efficient in terms of CPU time and memory handling, being a **compiled language**.
- High demand in industry.
- A (sometimes exceedingly) complex language: if you know C++ you will learn other languages quickly.
- A **strongly typed**$^1$ language: safer code, less ambiguous semantic, more efficient memory handling.
- Supporting functional, object-oriented, and generic programming.
- Backward compatible (unlike Python... :disappointed:). Old code compiles (almost) seamlessly.
- :evergreen_tree: It is [**green**](https://medium.com/codex/what-are-the-greenest-programming-languages-e738774b1957)!

$^1$Not everybody agrees on the definition of *strongly typed*.

---

# Outline

1. Structure of a basic C++ program
2. Fundamental types, variables, pointers, references, arrays
3. Conditional statements
4. Functions and operators
5. User-defined types: `struct`, `enum`, `union`, POD classes
6. Declarations and definitions
7. Code organization
8. The build toolchain in practice

---

<!--
_class: titlepage
-->

# Structure of a basic C++ program

---

# Structure of a basic C++ program

- C++ program structure includes a collection of functions.
- Every C++ program must contain one `main()` function, which serves as the entry point.
- Other functions can be defined as needed.
- Statements within functions are enclosed in curly braces `{}`.
- Statements are executed sequentially unless control structures (e.g., loops, conditionals) are used.

---

# Hello world!

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
```

 
- `#include <iostream>`: Includes the Input/Output stream library. 
- `int main()`: Entry point of the program. 
- `std::cout`: Standard output stream. 
- `<<`: Stream insertion operator. 
- `"Hello, world!"`: Text to be printed. 
- `<< std::endl`: End-of-line character. 
- `return 0;`: Indicates successful program execution.

---

# How to compile and run

To compile the program:

```bash
g++ -o HelloWorld HelloWorld.cpp
```



To run the compiled program:

```bash
./HelloWorld
```

---

# C++ as a strongly typed language

- C++ enforces strict type checking at compile time.
- Variables must be declared with a specific type.
- Type errors are detected and reported at compile time.
- This helps prevent runtime errors and enhances code reliability.

## Example

```cpp
int x = 5;
char ch = 'A';
float f = 3.14;

x = 1.6;        // Illegal
f = "a string"; // Illegal
```

---

<!--
_class: titlepage
-->

# Fundamental types, variables, pointers, references, arrays

---

# Fundamental types

| Data Type                | Size (Bytes) |
|--------------------------|--------------|
| `bool`                   | 1            |
| (`unsigned`) `char`      | 1            |
| (`unsigned`) `short`     | 2            |
| (`unsigned`) `int`       | 4            |
| (`unsigned`) `long`      | 4 or 8       |
| (`unsigned`) `long long` | 8            |
| `float`                  | 4            |
| `double`                 | 8            |
| `long double`            | 8, 12, or 16 |

---

# Integer numbers

- C++ provides several integer types with varying sizes. 
- Common integer types include `int`, `short`, `long`, and `long long`.
- The range of values that can be stored depends on the type.

## Example

```cpp
int age = 30;

short population = 32000;

long long largeNumber = 123456789012345;
```

---

# Floating-point numbers

- C++ supports floating-point types for representing real numbers. 
- Common floating-point types include `float`, `double`, and `long double`.
- These types can represent decimal fractions.

## Example

```cpp
float pi = 3.14;

double gravity = 9.81;
```

---

# Floating-point arithmetic

Floating-point arithmetic is a method for representing and performing operations on real numbers $\pm f \cdot b^e$ in a binary format (i.e., $b=2$).

- **Representation**: Floating-point numbers consist of three components: sign $s$: 0 (positive), 1 (negative), significand $f$, and exponent $e$.

- **Normalized numbers**: In normalized form, the most significant bit of the significand is always 1, allowing for a wide range of values to be represented efficiently.

- **IEEE 754 standard**: The most commonly adopted standard for floating-point arithmetic is the [IEEE 754 Standard for Floating-Point Arithmetic](https://ieeexplore.ieee.org/document/8766229). This standard specifies the formats, precision, rounding rules, and handling of special values like NaN (Not-a-Number) and infinity.

---

# Floating-point arithmetic limitations

```cpp
double epsilon = 1.0; // Machine epsilon.

while (1.0 + epsilon != 1.0) {
    epsilon /= 2.0;
}
```

```cpp
double a = 0.1, b = 0.2, c = 0.3;

if (a + b == c) { // Unsafe comparison.
    // This may not always be true due to precision limitations.
}
```

```cpp
double x = 1.0, y = 1.0 / 3.0;
double sum = y + y + y;

if (std::abs(x - sum) < tolerance) { // Safer comparison.
    // Use tolerance to handle potential rounding errors.
}
```

---

# Characters and strings

- Characters are represented using the `char` type. 
- Strings are sequences of characters and are represented using the `std::string` type.


## Example

```cpp
char grade = 'A';

std::string name = "John";

std::string greeting = "Hello, ";

// Concatenate strings
std::string message = greeting + name;
```

---

# Boolean types

- C++ has a built-in Boolean type called `bool`. 
- It can have two values: `true` or `false`.
- Useful for conditional statements and logical operations.

## Example

```cpp
bool is_true = true;

bool is_false = false;
```

---

# Variables

- Variables are named memory locations used to store data.
- They must be declared with a specific type before use.
- Variables can be modified and accessed in your program.

## Example

```cpp
int x = 5; // Declaration and initialization
x = 10;    // Variable modification

int y;  // Declaration with default initialization
y = 20; // Initialization after declaration

const double a = 3.7;
a = 5; // Error!
```

---

# Pointers

- Pointers are variables that store memory addresses.
- They allow you to work with memory directly. 
- Declared using `*` symbol.

## Example

```cpp
int number = 42;

int* pointer = &number; // Pointer to 'number'

// Create a dynamic integer with new
int* dynamic_variable = new int;
*dynamic_variable = 5;
delete dynamic_variable;
```

---

# References

- References provide an alias for an existing variable. 
- Declared using `&` symbol.
- Provide an alternative way to access a variable.

## Example

```cpp
int a = 10;
int& refA = a; // Reference to 'a'
```

---

# Arrays

- Arrays are collections of elements of the same type.
- Elements are accessed by their index (position).
- Arrays have a fixed size.

## Example

```cpp
int numbers[5]; // Array declaration
numbers[0] = 1; // Assigning values to elements
numbers[1] = 2;

// Create a dynamic array of integers with new
int* dynamicArray = new int[5];

for (int i = 0; i < 5; ++i) {
    dynamicArray[i] = i * 2;
}

delete[] dynamicArray;
```


---

<!--
_class: titlepage
-->

# Conditional statements

---

# `if`, `elseif`, `else`

- Conditional statements allow you to execute different code based on conditions. 
- In C++, we use `if`, `else if`, and `else` statements for conditional execution.

## Example

```cpp
int x = 10;

if (x > 5) {
    std::cout << "x is greater than 5." << std::endl;
} else if (x > 3) {
    std::cout << "x is greater than 3 but not greater than 5." << std::endl;
}
else {
    std::cout << "x is not greater than 5." << std::endl;
}
```

---

# `switch`, `case`

---

<!--
_class: titlepage
-->

# Functions and operators

---

# Functions
- Functions are blocks of code that perform a specific task.
- Functions are defined with a return type, name, and parameters.
- They can be called to execute their code.

## Example

```cpp
int add(int a, int b) {
    return a + b;
}

int result = add(3, 4); // Calling the 'add' function
```

---

# Pass by value vs. pointer vs. reference


---

# Operators

- Operators are symbols used to perform operations on variables and values. 
- Arithmetic operators: `+`, `-`, `*`, `/`, `%` 
- Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=` 
- Logical operators: `&&`, `||`, `!`

## Example

```cpp
int x = 5;
int y = 3;
bool isTrue = (x > y) && (x != 0); // Logical expression
```

# TODO: i++

---

<!--
_class: titlepage
-->

# User-defined types

---

# User-defined types: `enum`

- Enumerations (enums) allow you to define a set of named values.
- Enums provide a way to create user-defined data types.

## Example

```cpp
enum Color {
    Red,
    Green,
    Blue
};

Color myColor = Green;
```

---

# User-defined types: `union`

- Unions allow you to define a type that can hold different data types.
- Only one member of a union can be accessed at a time.
- Useful for optimizing memory usage.

## Example

```cpp
union MyUnion {
    int intValue;
    float floatValue;
};

MyUnion data;
data.intValue = 42;
```

---

# User-defined types: `struct`

- Structs (structures) allow you to group related data members into a single unit.
- Members can have different data types.
- Structs provide a way to create custom data structures.

## Example

```cpp
struct Point {
    int x;
    int y;
};

Point p;
p.x = 3;
p.y = 5;
```

---

# User-defined types: Plain Old Data (POD) classes

- POD classes are classes with simple data members and no user-defined constructors or destructors.
- They have C-like semantics and can be used in low-level operations.

## Example

```cpp
class Rectangle {
public:
    int width;
    int height;
};

Rectangle r;
r.width = 10;
r.height = 20;
```

---

# Looking towards classes

- Object-oriented programming (OOP) is a programming paradigm that uses classes and objects.
- C++ is an object-oriented language that supports OOP principles.
- Classes are user-defined data types that encapsulate data and behavior.
- OOP promotes code reusability, modularity, and organization.

---

<!--
_class: titlepage
-->

# Declarations and definitions

---

# What are declarations?

- Declarations inform the compiler about the existence of variables or functions.
- They provide type information but do not allocate memory or provide implementation details.
- Example of variable declaration:

```cpp
int x; // Declaration of 'x'

extern int y; // Declaration of 'y'
```

---

# What are definitions?

- Definitions provide the actual implementation of variables or functions.
- They allocate memory for variables or specify the behavior of functions.
- Example of variable definition:

```cpp
int x = 5; // Definition of 'x'
```

---

# Declaring variables

- Variable declarations specify their type and name.
- A declaration without initialization reserves memory but doesn't assign a value.

## Example

```cpp
extern int x; // Declaration of 'x'
```

---

# Defining variables

- Variables are defined when they are declared and initialized.

## Example

```cpp
int x = 5; // Definition and initialization of 'x'
```

---

# Initialization

- Initialization sets the initial value of a variable at the time of declaration.
- C++ supports various forms of initialization, including direct, copy, and list initialization.

## Example

```cpp
int x = 5;            // Direct initialization
int y(10);            // Constructor-style initialization
int z{15};            // Uniform initialization (preferred)
```

---

# Declaring functions
- Function declarations provide information about a function's interface.
- They specify the return type, name, and parameter types.

## Example

```cpp
int add(int a, int b); // Declaration of 'add' function
```

---

# Defining functions
- Function definitions specify the implementation of a function.
- They include the function's return type, name, parameters, and code block.

## Example

```cpp
int add(int a, int b) { // Definition of 'add' function
    return a + b;
}
```

---

# Function prototypes

- A function prototype is a declaration that provides enough information for the compiler to use the function.
- Prototypes are typically placed in header files.
- They enable the separation of interface (declaration) and implementation (definition).

## Example

```cpp
// Function prototype in a header file
int add(int a, int b);
```

---

<!--
_class: titlepage
-->

# Code organization

---

# Modular programming

- Modular programming divides code into separate modules or units.
- Each module focuses on a specific task or functionality. 
- Benefits:
  - Improved code organization and readability
  - Easier maintenance and debugging
  - Code reusability
  - Encapsulation of functionality

---

# Building blocks of C++ code modules

- C++ code modules consist of: 
- Header files (`.h` or `.hpp`) for declarations 
- Source files (`.cpp`) for definitions 
- Implementation files (`.cpp`) for non-template classes
- Header files contain function prototypes and class declarations.
- Source files contain function and class definitions.

---

# Header files: purpose and role

- Header files (`.h` or `.hpp`) contain declarations and prototypes.
- They define the interface to a module or class.
- Header files are included in source files to access declarations.
- Example of a header file:

```cpp
// MyModule.h
#pragma once

int add(int a, int b); // Function prototype
```

---

# Header files: best practices

- Use include guards or `#pragma once` to prevent multiple inclusions.
- Include only necessary headers to reduce compilation time.
- Keep header files concise and focused on declarations.
- Use descriptive and unique names for header files.
- Comment complex or non-obvious declarations.

---

# Source files: role and contents

- Source files (`.cpp`) contain the definitions of functions and classes.
- They implement the functionality declared in header files.
- Source files include header files for access to declarations.
- Example of a source file:

```cpp
// MyModule.cpp
#include "MyModule.h" // Include the corresponding header

int add(int a, int b) {
    return a + b;
}
```

---

# Compiling source files

- Compilation is the process of translating source code into machine code. 
- C++ source files are typically compiled into object files (`.o` or `.obj`).
- Object files are then linked together to create an executable. 
- The `g++` or `clang++` compiler is commonly used for C++ compilation.

---

# The need for header guards

- Header guards (or include guards) prevent multiple inclusions of the same header file.
- They ensure that a header file is included only once during compilation.
- Header guards are essential to avoid redefinition errors.
- Example of a header guard:

```cpp
// MyModule.h
#pragma once

// ... header content ...
```

---

# How to implement header guards

- Place `#pragma once` or `#ifndef`, `#define`, and `#endif` directives in the header file.
- Use a unique identifier (usually based on the filename) as the guard symbol.
- Example of header guards:

```cpp
// MyModule.h
#pragma once // or: #ifndef MYMODULE_H #define MYMODULE_H

// ... header content ...

// #endif // Add this line for the ifndef/define approach
```

---

# Preventing header file inclusion issues

- To avoid issues with header file inclusions:
- Include necessary headers in your source files.
- Avoid circular dependencies (A includes B, and B includes A).
- Use forward declarations when possible to minimize dependencies.
- Follow a consistent naming convention for header guards.

---

# Managing scope in C++

- Scope determines the visibility and lifetime of variables and functions.
- C++ uses blocks, functions, and namespaces to manage scope.
- Variables declared inside a block have block scope.
- Variables declared outside of any function or class have global scope.
- Namespaces help organize code and avoid naming conflicts.

---

# Using namespaces for organization

- Namespaces group related declarations to avoid naming collisions.
- They provide a way to organize code into logical units. 
- Namespace members are accessed using the `::` operator.
- Example of using a namespace:

```cpp
namespace Math {
    int add(int a, int b) {
        return a + b;
    }
}

int result = Math::add(3, 4); // Accessing a namespace member
```

---

<!--
_class: titlepage
-->

# The build toolchain in practice

---

# Preprocessor and compiler

- The preprocessor (`cpp`) handles preprocessing directives.
- It includes headers, performs macro substitution, and removes comments. 
- The compiler (`g++`, `clang++`) translates source code into object files. 
- Preprocessor and compiler commands are combined when you run `g++` or `clang++`.

---

# Linker

- The linker (`ld`) combines object files and resolves external references.
- It creates an executable program from multiple object files.
- Linker errors occur if functions or variables are not defined.

---

# Loader

- The loader loads the executable program into memory for execution.
- It allocates memory for the program's data and code sections.
- The operating system's loader handles this task.

---

<!--
_class: titlepage
-->

# :arrow_right: Classes and object-oriented programming
