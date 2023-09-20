<!--
marp: true
theme: default
color: black
size: 16:9

style: |
  section {
    font-size: 25px
  }
  section.frame {
    justify-content: flex-start;
    padding: 30px;
  }
  section.titlepage {
    justify-content: center;
    padding: 75px;
  }

class: frame
_class: titlepage

paginate: true
_paginate: skip
-->

# Lecture 1

## Introduction to Advanced Programming

### Pasquale Claudio Africa

### 26 Sep 2023

---

# Course Overview
- Welcome to the "Advanced Programming" course.
  - Objectives and expectations:
    - Equipping you with advanced programming skills.
    - Understanding the UNIX shell and the software build process.

---

# Importance of advanced programming skills:
  - In today's technology landscape, advanced programming is crucial for developing complex software systems.
  - **Career Opportunities and Industry Demands:**
    - Advanced programming skills open up a wide range of career opportunities:
      - Software Developer: Design and develop software applications.
      - Systems Architect: Plan and design complex software systems.
      - Data Scientist/Engineer: Analyze and process data using advanced algorithms.
      - DevOps Engineer: Automate software development and deployment processes.
      - Cybersecurity Analyst: Secure software systems and networks.

---

# Industry demands for advanced programming skills are driven by:
  - Rapid technological advancements.
  - The need for scalable and efficient software solutions.
  - Increased reliance on data-driven decision-making.
- Job market competitiveness and higher earning potential for skilled programmers.

---

# History of C++

## Introduction

The history of the C++ programming language is a remarkable journey through the evolution of computer science and software development. C++, often considered a superset of the C programming language, was designed with the goal of combining the low-level power of C with high-level features for structured programming. This chapter explores the origins, key milestones, and influential figures that shaped C++ into the versatile and widely-used language it is today.

---

### The Birth of C++

#### Early Roots: The C Language
C++ owes its existence to the C programming language, which was developed at Bell Labs in the early 1970s by Dennis Ritchie. C quickly gained popularity due to its efficiency, portability, and the flexibility it offered to system programmers. Its simplicity, combined with powerful features for memory manipulation, made it a go-to language for developing operating systems and other system software.

#### Bjarne Stroustrup's Vision
The story of C++ begins in 1979 when Bjarne Stroustrup, a Danish computer scientist, started working on what he initially called "C with Classes." Stroustrup, then at Bell Labs, aimed to enhance C by adding support for object-oriented programming (OOP) concepts. His motivation was to create a language that could address the growing complexity of software systems while maintaining the performance and control of C.

---

#### From C with Classes to C++
Stroustrup's work on extending C led to the development of a preprocessor called "Cfront" in 1983. Cfront allowed C++ code to be translated into C code, which could then be compiled using standard C compilers. This approach eased the transition to C++ for existing C programmers.

#### The Birth of C++
In 1983, the name "C++" was coined, signifying the evolution of C with Classes. The term "C++" represents the incremental increase operator in C, suggesting that C++ is an improved version of C. In 1985, Stroustrup published the first edition of "The C++ Programming Language," a seminal book that introduced programmers to the language's concepts and features.

---

## Early Growth and Standardization

### ANSI C++ Standardization
As C++ gained popularity, there was a need for standardization to ensure compatibility across different compilers and platforms. In 1989, the American National Standards Institute (ANSI) began working on a standard for the C++ language. This effort culminated in the release of the ANSI C++ standard in 1998, which provided a formal specification of the language.

### Object-Oriented Paradigm
C++ introduced essential features of the OOP paradigm, including classes, objects, inheritance, and polymorphism. These features allowed developers to build more modular and maintainable software by encapsulating data and behavior within objects.

---

### Template Metaprogramming
Another significant innovation in C++ was the introduction of templates. Templates allowed for generic programming, enabling the creation of data structures and algorithms that could work with different data types. Template metaprogramming, a technique that uses templates for compile-time computations, further expanded C++'s capabilities.

---

## C++ in the Modern Era
### Standardization Efforts

The C++ language has continued to evolve through a series of standards, each introducing new features and improvements. Notable standards include C++98, C++11, C++14, C++17, and C++20. These standards have added features like smart pointers, lambda expressions, range-based for loops, and modules, enhancing the language's expressiveness and safety.

### Open Source and the C++ Community

C++'s success can be attributed in part to the vibrant open-source community that has formed around it. Open-source libraries and frameworks, such as the Boost C++ Libraries, have extended C++'s functionality and encouraged collaborative development.

---

### C++ in Industry
C++ has found applications in a wide range of fields, including game development, finance, embedded systems, and scientific computing. Its combination of performance, portability, and expressive power makes it a versatile choice for building software across various domains.

## The Future of C++
C++ continues to evolve, with ongoing work on future language standards. Concepts like concepts (a type of compile-time constraint) and modules (for better code organization and encapsulation) are expected to play a significant role in shaping the language's future.

---

## Conclusion
The history of C++ is a testament to the enduring power of a well-designed programming language. From its humble beginnings as an extension of C to its status as a modern, versatile language, C++ has left an indelible mark on the world of software development. Its rich history, coupled with ongoing innovations, ensures that C++ will remain a vital tool for programmers for years to come.

---

# History of Python

## Introduction
Python is a versatile and widely-used programming language known for its simplicity, readability, and the ease with which it allows developers to write clean and maintainable code. This chapter delves into the rich history of Python, tracing its origins, key milestones, and the individuals who played pivotal roles in its development.

---

### The Genesis of Python

#### Guido van Rossum's Brainchild
Python was created by Guido van Rossum, a Dutch programmer, in the late 1980s. Guido started working on Python in December 1989 during his time at the Centrum Wiskunde & Informatica (CWI) in the Netherlands. His motivation was to develop a language that combined the simplicity of ABC (a programming language he had worked on previously) with the extensibility of the Amoeba operating system.

#### Python's Name and Design Philosophy
Guido named the language after his love for the British comedy group Monty Python. Python's design philosophy, often referred to as the "Zen of Python," emphasizes readability, simplicity, and elegance. This philosophy is encapsulated in the "PEP 20" document, which includes guiding aphorisms like "Readability counts" and "There should be one—and preferably only one—obvious way to do it."

---

## Python's Early Years

### Python 0.9.0
Python's first public release, Python 0.9.0, occurred in February 1991. This release introduced essential features like exception handling, functions, and modules, which laid the foundation for the language's future growth.

### The Python Software Foundation
In 2001, the Python Software Foundation (PSF) was established as a non-profit organization to promote and support Python. The PSF plays a crucial role in managing Python's development, organizing conferences (e.g., PyCon), and providing grants and resources to the Python community.

---

## Python 2.x and 3.x

### The Transition to Python 3
Python 2.x and Python 3.x marked a significant phase in Python's history. Python 3, released in December 2008, introduced backward-incompatible changes to address shortcomings in the language. While Python 2 continued to be used for some time, the Python community has actively encouraged the transition to Python 3.

---

## Python's Popularity and Versatility
### Python's Ubiquity
Python's readability, simplicity, and extensive standard library contributed to its widespread adoption. It became a go-to language for web development, scientific computing, data analysis, and automation. Popular web frameworks like Django and Flask further fueled Python's growth.
Python in Data Science and Machine Learning

Python gained prominence in data science and machine learning due to libraries like NumPy, pandas, scikit-learn, and TensorFlow. Its ease of use and rich ecosystem made it a favorite among data scientists and engineers.

--- 
### Python in Education
Python's readability and simplicity have made it an excellent choice for teaching programming. It is widely used in educational settings to introduce programming concepts to beginners.

---
## The Future of Python

### Python's Ongoing Development
Python continues to evolve through a series of releases, with each version bringing new features and enhancements. Python's community-driven development process ensures that the language remains vibrant and relevant.

### Emerging Trends
Python is well-positioned to thrive in emerging areas like artificial intelligence, web development, and cloud computing. Its adaptability and large community ensure it can address a wide range of challenges.

---

## Conclusion
The history of Python is a testament to the enduring impact of a well-designed programming language. From its inception in the late 1980s to its current status as a versatile and ubiquitous language, Python has empowered developers to create a diverse array of software solutions. Its readability, simplicity, and thriving community ensure that Python will remain a cornerstone of the programming landscape for years to come.

---

# Scientific Packages in C++:

1. **Eigen**:
   - Eigen is a highly regarded C++ template library for linear algebra.
   - It provides efficient and robust support for matrix operations, solving linear equations, and eigenvalue problems.
   - Eigen is used in various scientific and engineering applications, including computer graphics, robotics, and scientific simulations.

2. **FLANN**:
   - The Fast Library for Approximate Nearest Neighbors (FLANN) is a C++ library for high-dimensional data structures.
   - FLANN offers efficient algorithms for nearest neighbor search, making it valuable in fields like machine learning, computer vision, and data mining.

---

# Scientific Packages in C++:

3. **Boost.Python**:
   - Boost.Python is an extension to the Boost C++ Libraries that enables seamless integration of C++ libraries with Python.
   - It allows C++ developers to create Python bindings for their C++ code, facilitating the use of C++ libraries in Python applications.

---

# Scientific Packages in Python:

1. **NumPy**:
   - NumPy is a fundamental package for scientific computing in Python.
   - It provides support for arrays and matrices, along with a vast library of mathematical functions to operate on them.
   - NumPy is the foundation for many other Python scientific libraries, making it a crucial component of the scientific Python ecosystem.

2. **SciPy**:
   - SciPy is built on top of NumPy and offers additional functionality for scientific and technical computing.
   - It provides modules for optimization, integration, interpolation, linear algebra, and more.
   - SciPy is widely used in fields like physics, engineering, and biology.

---

# Scientific Packages in Python:

3. **Matplotlib**:
   - Matplotlib is a 2D plotting library for Python that produces high-quality figures and plots.
   - It is extensively used for data visualization in scientific research, data analysis, and presentations.
   - Matplotlib's versatility allows users to create a wide range of plots and charts.

4. **Pandas**:
   - Pandas is a powerful library for data manipulation and analysis.
   - It offers data structures like DataFrames and Series, making it convenient for handling structured data.
   - Pandas is widely used in data science and scientific research for tasks such as data cleaning, exploration, and analysis.

---

# Popularity of Programming Languages

![](images/01_popularity.png)

Source: https://pypl.github.io/PYPL.html

---

# UNIX Shell Fundamentals
- Introduction to the UNIX operating system:
  - Historical context: Origin of UNIX and its role in shaping modern computing.
  - Significance: UNIX's influence on open-source operating systems and cloud technologies.
- Common UNIX-based systems:
  - Linux distributions (e.g., Ubuntu, CentOS) and macOS.
- The concept of a shell:
  - The shell as a command-line interface (CLI) for interacting with the operating system.
  - Different types of shells (e.g., Bash, Zsh) and their features.

---

# Basic UNIX Shell Commands
- Navigating the file system:
  - `cd` (Change Directory):
    - Usage and examples of navigating between directories.
    - **Exercise:**
      - Navigate to your home directory: `cd ~`
  - `ls` (List):
    - Detailed explanation of `ls` and its various options.
    - **Exercise:**
      - List files in the current directory, including hidden files: `ls -la`
  - `pwd` (Print Working Directory):
    - Demonstrating how to find the current working directory.
    - **Exercise:**
      - Print the current working directory: `pwd`

---

# File manipulation:
  - `cp` (Copy), `mv` (Move), `rm` (Remove), `mkdir` (Make Directory):
    - In-depth look at file and directory manipulation commands.
    - **Exercises:**
      - Copy a file from one directory to another.
      - Move a file to a different directory and rename it.
      - Create and remove directories.

- Text manipulation:
  - `cat` (Concatenate), `grep` (Global Regular Expression Print), `sed` (Stream Editor), `awk` (Text Processing):
    - Comprehensive explanation of text processing commands.
    - **Practical examples and exercises:**
      - Search for a specific word in a text file.
      - Replace text in a file.
      - Extract specific information from a CSV file.

---

# Pipes and Redirection
- Using pipes (`|`) to chain commands:
  - Detailed examples of using pipes to combine commands for more advanced operations.
  - **Exercise:**
    - Create a data processing pipeline to count the number of lines containing a specific word in a set of text files.
- Redirection operators:
  - `>` (Output Redirection), `<` (Input Redirection), `>>` (Append Output):
    - Explaining how redirection operators work.
    - **Exercises:**
      - Redirect command output to a file.
      - Append output to an existing log file.

---

# Shell Scripting
- Introduction to shell scripting:
  - What is shell scripting, and why is it useful?
    - Shell scripting refers to the practice of writing scripts or programs that automate tasks and interact with the operating system via the shell.
    - It is useful for automating repetitive tasks, performing system maintenance, and managing data processing.
- Creating and running shell scripts:
  - Step-by-step guide on creating shell scripts.
    - Create a new file, give it execute permissions, and define the shell to use.
  - How to set execute permissions and execute scripts.
    - Explain how to make a script executable using the `chmod` command.
    - Demonstrate script execution using the `./scriptname.sh` syntax.
  - **Exercise:**
    - Write a shell script that automates the process of creating a backup of a specified directory.

---

# Variables, control structures, and functions in shell scripts:
  - Variables: Variable types, naming conventions, and assigning values.
    - Cover integer and string variables, naming rules (no spaces, special characters), and variable assignment.
  - Control structures: Using if statements and loops for decision-making and iteration.
    - Explain the syntax and use cases for `if`, `else`, `elif`, `for`, and `while` statements.
  - Functions: Defining and calling functions in shell scripts.
    - Define functions, pass arguments, and return values.
  - **Exercise:**
    - Create a script that reads data from a file, calculates statistics, and displays the results.

---

# Practical Exercises
- Hands-on exercises to reinforce learning:
  - Writing complex shell scripts.
    - Encourage students to combine concepts like variables, control structures, and functions in their scripts.
  - Automating tasks using shell commands.
    - Challenge students to solve real-world problems using the shell, such as automating file processing or data manipulation.
  - Solving real-world problems with shell scripting.
    - Provide practical scenarios (e.g., log file analysis, data transformation) for students to solve using shell scripts.
  - **Exercise (Continued):**
    - Choose one of the practical exercises mentioned and work on it during the lecture, providing guidance and support as needed.

---

# The Build Process
- Understanding the software build process:
  - Definition and significance of the build process in software development.
    - Emphasize that the build process transforms human-readable source code into machine-executable programs.
    - Explain its significance in ensuring code quality, portability, and optimization.
  - How a high-level programming language gets transformed into an executable program.
    - Walk through the stages: source code, preprocessing, compilation, linking, and loading.
  - **Exercise:**
    - Illustrate the build process for a simple C program, demonstrating each stage with real code.

---

# Phases of the build process:
  - Preprocessor:
    - Role of the preprocessor in C/C++ programming.
      - Explain how it handles macro expansion, file inclusion (e.g., `#include`), and conditional compilation (e.g., `#ifdef`).
    - **Exercise:**
      - Create a C program with header files and demonstrate preprocessing, including macro expansion.
  - Compiler:
    - Compilation process: From source code to object files.
      - Describe the steps of lexical analysis, syntax analysis, and code generation.
      - Introduce common compilers (e.g., GCC, Clang).
      - Discuss compilation flags and options for optimization and debugging.
    - **Exercise:**
      - Compile a C program with different optimization flags and examine the resulting object files.
  - Linker:
    - Linking object files, resolving symbols, and generating executables.
      - Explain how the linker resolves symbols (functions and variables) and creates a cohesive program.
      - Differentiate between dynamic linking (shared libraries) and static linking (self-contained executables).
    - **Exercise:**
      - Create object files and link them into an executable program.
  - Loader:
    - Loading executables into memory, address space, and execution process.
      - Describe how the loader maps the program into memory and prepares it for execution.
      - Discuss the role of system libraries and shared objects in program execution.
    - **Exercise:**
      - Investigate the memory layout of a running program using system tools like `ps` and `top`.

---

# Overview of build automation tools:
  - Introduction to build automation tools like Make and CMake.
    - Explain the purpose of build automation tools in simplifying complex build processes.
    - Provide a high-level overview of how these tools work.

---

# Conclusion
- Recap of key points covered in this comprehensive lecture:
  - Highlight the main concepts and skills learned, including shell commands, shell scripting, and the software build process.
- Encouragement to explore further, practice, and apply the knowledge gained:
  - Emphasize the importance of hands-on practice and experimentation.
  - Suggest additional resources for students to deepen their understanding.
- Preparing students for the next lecture and assignments:
  - Provide an overview of the topics to be covered in the next lecture.
  - Mention any assignments or readings students should complete before the next class.
