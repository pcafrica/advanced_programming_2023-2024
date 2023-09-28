<!--
title: Lecture 02

_class: titlepage

paginate: true
_paginate: skip
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
_paginate: skip
-->

# Structure of a basic C++ program

---

# Hello world!


---

# How to compile and run

---

# C++ as a strongly typed language


---

<!--
_class: titlepage
_paginate: skip
-->

# Fundamental types, variables, pointers, references, arrays

---

# Integer numbers

---

# Floating-point numbers

---

# Characters and strings

---

# Boolean types

---

# Variables


---

# Pointers


---

# References


---

# Arrays


---

<!--
_class: titlepage
_paginate: skip
-->

# Conditional statements

---

<!--
_class: titlepage
_paginate: skip
-->

# Functions and operators

---

# Functions

---

# Operators

---

<!--
_class: titlepage
_paginate: skip
-->

# User-defined types

---

# User-defined types: `enum`


---

# User-defined types: `union`


---

# User-defined types: `struct`


---

# User-defined types: Plain Old Data (POD) classes


---

# Looking towards classes


---

<!--
_class: titlepage
_paginate: skip
-->

# Declarations and definitions

---

# What are definitions?

---

# What are declarations?

---

# Defining variables

---

# Declaring variables

---

# Initialization

The options for initializing objects bewilder even experienced C++ programmers. Here’s a general rule to make initialization simple: *use braced-­initializers* everywhere. Braced initializers work as intended almost everywhere, and they cause the fewest surprises. For this reason, braced initialization is also called *uniform initialization*. The remainder of the course follows this guidance.


---

# Defining functions

---

# Declaring functions

---

# Function prototypes

---

<!--
_class: titlepage
_paginate: skip
-->

# Code organization

---
# Benefits of modular programming

---

# Building blocks of C++ code modules

---

# Header files: purpose and role

---

# Header files: best practices
 
---

# Source files: role and contents

---

# Compiling source files

---

# The need for header huards

---

# How to implement header guards

---

# Preventing header file inclusion issues

---

# Managing scope in C++

---

# Using namespaces for organization

---

<!--
_class: titlepage
_paginate: skip
-->

# The build toolchain in practice

---

# Preprocessor and compiler

---

# Linker

---

# Loader

---

<!--
_class: titlepage
_paginate: skip
-->

# :arrow_right: Classes and object-oriented programming
