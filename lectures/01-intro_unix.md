<!--
title: Lecture 1

_class: titlepage

paginate: true
_paginate: skip
-->

# Lecture 1
<br>

## Introduction to the course. The UNIX shell. The build process.
<br>
<br>

#### Advanced Programming - SISSA, UniTS, 2023 - 2024

###### Pasquale Claudio Africa

###### 26 Sep 2023

---

# About me

# Experience

# Research interests


---

# Outline

1. Course introduction.
2. History of C++.
3. History of Python.
4. The build process.
5. Introduction to the UNIX shell.
6. Introduction to `git`.

---

<!--
_class: titlepage
_paginate: skip
-->

# Course overview.

---

# Objectives and expectations
- UNIX shell and the software build process.
- Advanced programming concepts, specifically in C++ and Python.
- Object-oriented and generic programming paradigms.
- Common data structures, algorithms, libraries for scientific computing.
- Software development tools in Linux (software documentation, version control, testing, and project management).

## Required skills:
- Former knowledge of programming fundamentals (syntax, data types, variables, control structures, functions).
- Prior experience with C, C++, Java, or Python, is **recommended**, not mandatory.

---

# Practical info
- Instructor: Pasquale Claudio Africa <pafrica@sissa.it>
- Tutor: Marco Feder <mfeder@sissa.it>

Lectures at SISSA, check the website for info.

## Course material:
- [MOODLE2](https://moodle2.units.it/): please **subscribe** to the "Advanced Programming" course.
- [GitHub](https://github.com/pcafrica/advanced_programming_2023-2024): timetable, lecture notes and slides, exercise sessions.
- [Microsoft Teams](https://teams.microsoft.com/l/team/19%3aEIKgrGVL57W04_30eEccPsxL1E6SwQxOn914a-rwiIY1%40thread.tacv2/conversations?groupId=161c59e5-2a78-4bd8-8eb2-085d0d2ea5a8&tenantId=a54b3635-128c-460f-b967-6ded8df82e75): live streaming, recordings.

## Other resources:
- Books (see
- Internet (plenty of free or paid resources)

---

# Practical info

Course content
Bring your laptop

# Office hours
- Use Forum on [MOODLE2](https://moodle2.units.it/), engage with each other!

- Wrap-up day-by-day
- Engage with exercises
- Ask questions

---

# Exams

---

# Laptop configuration
https://ubuntu.com/tutorials/install-ubuntu-desktop
 
---

# AI2S Welcome Day

- When: 27 Sep, 19:00 - 01:00
- Where: Loft (via Giovanni e Demetrio Economo 12)
- Form: http://bit.ly/AI2SWelcomeDay

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

# Why should I learn programming in the ChatGPT era?

- Artifial Intelligence has **no** creativity!
- 

---

<!--
_class: noborder
-->

# Time for a poll!
<br><br><br><br>

# http://etc.ch/TVQS

![bg right:50% w:500](http://etc.ch/TVQS?qr)

---

<!--
_class: titlepage
_paginate: skip
-->

# History of C++.

---

# History of C++

## Introduction

The history of the C++ programming language is a remarkable journey through the evolution of computer science and software development. C++, often considered a superset of the C programming language, was designed with the goal of combining the low-level power of C with high-level features for structured programming. This chapter explores the origins, key milestones, and influential figures that shaped C++ into the versatile and widely-used language it is today.

---

# The birth of C++

## Early roots: the C language
C++ owes its existence to the C programming language, which was developed at Bell Labs in the early 1970s by Dennis Ritchie. C quickly gained popularity due to its efficiency, portability, and the flexibility it offered to system programmers. Its simplicity, combined with powerful features for memory manipulation, made it a go-to language for developing operating systems and other system software.

---

# The birth of C++

## Bjarne Stroustrup's vision
The story of C++ begins in 1979 when Bjarne Stroustrup, a Danish computer scientist, started working on what he initially called "C with Classes." Stroustrup, then at Bell Labs, aimed to enhance C by adding support for object-oriented programming (OOP) concepts. His motivation was to create a language that could address the growing complexity of software systems while maintaining the performance and control of C.

---

# The birth of C++

## From C with classes to C++
Stroustrup's work on extending C led to the development of a preprocessor called "Cfront" in 1983. Cfront allowed C++ code to be translated into C code, which could then be compiled using standard C compilers. This approach eased the transition to C++ for existing C programmers.

In 1983, the name "C++" was coined, signifying the evolution of C with Classes. The term "C++" represents the incremental increase operator in C, suggesting that C++ is an improved version of C. In 1985, Stroustrup published the first edition of "The C++ Programming Language," a seminal book that introduced programmers to the language's concepts and features.

---

# Early growth and ANSI C++ standardization
As C++ gained popularity, there was a need for standardization to ensure compatibility across different compilers and platforms. In 1989, the American National Standards Institute (ANSI) began working on a standard for the C++ language. This effort culminated in the release of the ANSI C++ standard in 1998, which provided a formal specification of the language.

---

# Object-Oriented paradigm
C++ introduced essential features of the OOP paradigm, including classes, objects, inheritance, and polymorphism. These features allowed developers to build more modular and maintainable software by encapsulating data and behavior within objects.

# Template metaprogramming
Another significant innovation in C++ was the introduction of templates. Templates allowed for generic programming, enabling the creation of data structures and algorithms that could work with different data types. Template metaprogramming, a technique that uses templates for compile-time computations, further expanded C++'s capabilities.

---

# C++ in the modern era

## Standardization efforts
The C++ language has continued to evolve through a series of standards, each introducing new features and improvements. Notable standards include C++98, C++11, C++14, C++17, and C++20. These standards have added features like smart pointers, lambda expressions, range-based for loops, and modules, enhancing the language's expressiveness and safety.
<br>
## Open source and the C++ community
C++'s success can be attributed in part to the vibrant open-source community that has formed around it. Open-source libraries and frameworks, such as the Boost C++ Libraries, have extended C++'s functionality and encouraged collaborative development.

---

# The future of C++

C++ has found applications in a wide range of fields, including game development, finance, embedded systems, and scientific computing. Its combination of performance, portability, and expressive power makes it a versatile choice for building software across various domains.

C++ continues to evolve, with ongoing work on future language standards. Concepts like concepts (a type of compile-time constraint) and modules (for better code organization and encapsulation) are expected to play a significant role in shaping the language's future.

The history of C++ is a testament to the enduring power of a well-designed programming language. From its humble beginnings as an extension of C to its status as a modern, versatile language, C++ has left an indelible mark on the world of software development. Its rich history, coupled with ongoing innovations, ensures that C++ will remain a vital tool for programmers for years to come.

---

<!--
_class: titlepage
_paginate: skip
-->

# History of Python.

---

# History of Python

## Introduction
Python is a versatile and widely-used programming language known for its simplicity, readability, and the ease with which it allows developers to write clean and maintainable code. This chapter delves into the rich history of Python, tracing its origins, key milestones, and the individuals who played pivotal roles in its development.

---

# The Genesis of Python

## Python's name and design philosophy
Python was created by Guido van Rossum, a Dutch programmer, in the late 1980s. Guido started working on Python in December 1989 during his time at the Centrum Wiskunde & Informatica (CWI) in the Netherlands. His motivation was to develop a language that combined the simplicity of ABC (a programming language he had worked on previously) with the extensibility of the Amoeba operating system.

Guido named the language after his love for the British comedy group Monty Python. Python's design philosophy, often referred to as the "Zen of Python," emphasizes readability, simplicity, and elegance. This philosophy is encapsulated in the "PEP 20" document, which includes guiding aphorisms like "Readability counts" and "There should be one—and preferably only one—obvious way to do it."

---

# Python's early years

## Python 0.9.0
Python's first public release, Python 0.9.0, occurred in February 1991. This release introduced essential features like exception handling, functions, and modules, which laid the foundation for the language's future growth.
<br>
## The Python Software Foundation
In 2001, the Python Software Foundation (PSF) was established as a non-profit organization to promote and support Python. The PSF plays a crucial role in managing Python's development, organizing conferences (e.g., PyCon), and providing grants and resources to the Python community.

---

# Python 2.x and 3.x

## The transition to Python 3
Python 2.x and Python 3.x marked a significant phase in Python's history. Python 3, released in December 2008, introduced backward-incompatible changes to address shortcomings in the language. While Python 2 continued to be used for some time, the Python community has actively encouraged the transition to Python 3.

---

# Python's popularity and versatility
Python's readability, simplicity, and extensive standard library contributed to its widespread adoption. It became a go-to language for web development, scientific computing, data analysis, and automation. Popular web frameworks like Django and Flask further fueled Python's growth.
Python in Data Science and Machine Learning

Python gained prominence in data science and machine learning due to libraries like NumPy, pandas, scikit-learn, and TensorFlow. Its ease of use and rich ecosystem made it a favorite among data scientists and engineers.

Python's readability and simplicity have made it an excellent choice for teaching programming. It is widely used in educational settings to introduce programming concepts to beginners.

---

# The future of Python
Python continues to evolve through a series of releases, with each version bringing new features and enhancements. Python's community-driven development process ensures that the language remains vibrant and relevant.

Python is well-positioned to thrive in emerging areas like artificial intelligence, web development, and cloud computing. Its adaptability and large community ensure it can address a wide range of challenges.

The history of Python is a testament to the enduring impact of a well-designed programming language. From its inception in the late 1980s to its current status as a versatile and ubiquitous language, Python has empowered developers to create a diverse array of software solutions. Its readability, simplicity, and thriving community ensure that Python will remain a cornerstone of the programming landscape for years to come.

---

# Popularity of programming languages
<br>

![w:1200](images/01_popularity.png)
<br>

Source: https://pypl.github.io/PYPL.html

---

# Scientific packages in C++:

1. **Eigen**:
   - Eigen is a highly regarded C++ template library for linear algebra.
   - It provides efficient and robust support for matrix operations, solving linear equations, and eigenvalue problems.
   - Eigen is used in various scientific and engineering applications, including computer graphics, robotics, and scientific simulations.

2. **FLANN**:
   - The Fast Library for Approximate Nearest Neighbors (FLANN) is a C++ library for high-dimensional data structures.
   - FLANN offers efficient algorithms for nearest neighbor search, making it valuable in fields like machine learning, computer vision, and data mining.

---

# Scientific packages in C++:

3. **Boost.Python**:
   - Boost.Python is an extension to the Boost C++ Libraries that enables seamless integration of C++ libraries with Python.
   - It allows C++ developers to create Python bindings for their C++ code, facilitating the use of C++ libraries in Python applications.

---

# Scientific packages in Python:

1. **NumPy**:
   - NumPy is a fundamental package for scientific computing in Python.
   - It provides support for arrays and matrices, along with a vast library of mathematical functions to operate on them.
   - NumPy is the foundation for many other Python scientific libraries, making it a crucial component of the scientific Python ecosystem.

2. **SciPy**:
   - SciPy is built on top of NumPy and offers additional functionality for scientific and technical computing.
   - It provides modules for optimization, integration, interpolation, linear algebra, and more.
   - SciPy is widely used in fields like physics, engineering, and biology.

---

# Scientific packages in Python:

3. **Matplotlib**:
   - Matplotlib is a 2D plotting library for Python that produces high-quality figures and plots.
   - It is extensively used for data visualization in scientific research, data analysis, and presentations.
   - Matplotlib's versatility allows users to create a wide range of plots and charts.

4. **Pandas**:
   - Pandas is a powerful library for data manipulation and analysis.
   - It offers data structures like DataFrames and Series, making it convenient for handling structured data.
   - Pandas is widely used in data science and scientific research for tasks such as data cleaning, exploration, and analysis.

---

<!--
_class: titlepage
_paginate: skip
-->

# The build process:<br>Preprocessor, Compiler, Linker, Loader.

---

## Lecture Overview

- Explore the roles of the preprocessor, compiler, linker, and loader.
- Understand the build process.
- Identify common issues during compilation and linking.
- Appreciate efficient code generation and optimization.

### Learning Objectives

- Explain preprocessor, compiler, linker, loader functions.
- Describe the build process sequence.
- Recognize compilation and linking problems.
- Understand code generation and optimization importance.

---

# Preprocessor

## The Preprocessor: Overview

- Handles directives and macros before compilation.
- Originated for code reusability and organization.

### Preprocessor Directives

- `#include`: Includes header files.
- `#define`: Defines macros for code replacement.
- `#ifdef`, `#ifndef`, `#else`, `#endif`: Conditional compilation.
- `#pragma`: Compiler-specific directives.

### Macros

- Example: `#define SQUARE(x) ((x) * (x))`
- Usage: `int result = SQUARE(5); // Expands to: ((5) * (5))`

---

# Compiler

## The Compiler: Role and Significance

- Translates source code into assembly/machine code.
- Evolved with programming languages and instructions.

### Compilation Process

1. Lexical analysis: Tokenization.
2. Syntax analysis (parsing): Syntax tree.
3. Semantic analysis: Checking.
4. Code generation: Assembly/machine code.
5. Optimization: Efficiency improvement.
6. Output: Object files.

### Compiler Options

- `-O`: Optimization levels.
- `-g`: Debugging info.
- `-std`: C++ standard.

---

# Linker

## The Linker: Connecting Object Files

- Combines object files into an executable.
- Supports modular code.

### Linking Process

1. Symbol resolution: Match symbols.
2. Relocation: Adjust addresses.
3. Output: Executable.
4. Linker errors/warnings.
5. Example: `g++ -o my_program main.o helper.o`

### Static vs. Dynamic Linking

- Static: Larger binary, library inclusion.
- Dynamic: Smaller, runtime library reference.

---

# Loader

## The Loader: Bringing Executables to Memory

- Loads executables for execution.
- Tied to memory management evolution.

### Loading Process

1. Memory allocation: Reserve memory.
2. Relocation: Adjust addresses.
3. Initialization: Set up environment.
4. Execution: Start execution.

### Example

```
Loading program: my_program
Memory allocated: 0x1000 - 0x3000
Relocating addresses...
Initializing...
Executing...
```


### Dynamic Linking at Runtime

- Inclusion of external libraries during execution.
- Enhances flexibility.

---

# Conclusion

## Key Takeaways

- Understand build process.
- Roles of preprocessor, compiler, linker, loader.
- Compiler options and linking impact.
- Dynamic linking for flexibility.

## Encouragement and Next Steps

- Practice coding and building.
- Explore advanced compiler features.
- Preview debugging and profiling techniques.

---

<!--
_class: titlepage
_paginate: skip
-->

# Introduction to the UNIX shell.

---

# What is a shell?

![bg right width:600](images/01_shell.png)

From [http://www.linfo.org/shell.html](http://www.linfo.org/shell.html):

*"A shell is a program that provides the traditional, text-only user interface for Linux and other Unix-like operating systems. Its primary function is to read commands that are typed into a console [...] and then execute (i.e., run) them. The term shell derives its name from the fact that it is an outer layer of an operating system. A shell is an interface between the user and the internal parts of the OS (at the very core of which is the kernel)."*

---

# What is `Bash`?
`Bash` stands for: `Bourne Again Shell`, a homage to its creator Stephen Bourne. It is the default shell for most Unix systems and Linux distributions. It is both a command interpreter and a scripting language. The shell might be changed by simply typing its name and even the default shell might be changed for all sessions.

macOS has replaced it with [zsh](https://support.apple.com/en-us/HT208050), which is mostly compatible with `Bash`, since v10.15 Catalina.

---

# Variables and environmental variables
Since the shell is a program, as in all programs there are variables. You can assign a value to a variable with the equal sign **(no spaces!)**, for instance type `A=1`. You can then retrieve its value using the dollar sign and curly braces, for instance to display it the user may type `echo ${A}`. Some variables can affect the way running processes will behave on a computer, these are called **environmental variables**. For this reason, some variables are set by default, for instance to display the user home directory type `echo ${HOME}`. To set an environmental variable just prepend `export`, for instance `export PATH="/usr/sbin:$PATH"` adds the folder `/usr/sbin` to the `PATH` environment variable. `PATH` specifies a set of directories where executable programs are located.

---

# Types of shell
The first distinction that we make is between:
* A **login** shell logs you into the system as a specific user (it requires username and password). When you hit `Ctrl+Alt+F1` to login into a virtual terminal you get after successful login: a login shell (that is interactive).
* A **non-login** shell is executed without logging in (it requires a current logged in user). When you open a graphic terminal it is a non-login (interactive) shell. 

---

# Types of shell
The second distinction we make is between:
* In an **interactive** shell (login or non-login) you can interactively type or interrupt commands. For example a graphic terminal (non-login) or a virtual terminal (login). In an interactive shell the prompt variable must be set (`$PS1`).
* A **non-interactive** (sub)shell is usually run from an automated process. Input and output are not exposed (unless explicitly handled by the calling process). This is normally a non-login shell, because the calling user has logged in already. A shell running a script is always a non-interactive shell (but the script can emulate an interactive shell by prompting the user to input values).

---

# `Bash` as a command line interpreter
When launching a terminal a Unix system first launches the shell interpreter specified in the `SHELL` **environment variable**. If `SHELL` is unset it uses the system default.

After having sourced the initialization files, the interpreter shows the **prompt** (defined by the environment variable `$PS1`).

Initialization files are hidden files stored in the user's home directory, executed as soon as an **interactive** shell is run. 

---

# Initialization files
- **login**:
        - `/etc/profile`, `/etc/profile.d/*`, `~/.profile` for Bourne-compatible shells
            - `~/.bash_profile` (or `~/.bash_login`) for `Bash`
            - `/etc/zprofile`, `~/.zprofile` for `zsh`
            - `/etc/csh.login`, `~/.login` for `csh`

- **non-login**: `/etc/bash.bashrc`, `~/.bashrc` for `Bash`

- **interactive**:
            - `/etc/profile`, `/etc/profile.d/*` and `~/.profile`
            - `/etc/bash.bashrc`, `~/.bashrc` for `Bash`

- **non-interactive**:
            - `/etc/bash.bashrc` for `Bash` (but most of the times the script begins with: `[ -z "$PS1" ] && return`, *i.e.* don't do anything if it's a non-interactive shell).
            - depending on the shell, the file specified in `$ENV` (or `$BASH_ENV`)  might be read.

---

# Getting started
To get a little hang of the bash, let’s try a few simple commands:
- `echo`: returns whatever you type at the shell prompt similar to `print` in Python, or `disp` in MATLAB.
- `date`: displays the current time and date.
- `clear`: clean the terminal.

---

# Basic Bash commands
- `pwd` stands for **Print working directory** and it points to the current working directory, that is, the directory that the shell is currently looking at. It’s also the default place where the shell commands will look for data files.
- `ls` stands for a **List** and it lists the contents of a directory. ls usually starts out looking at our home directory. This means if we print ls by itself, it will always print the contents of the current directory.
- `cd` stands for **Change directory** and changes the active directory to the path specified.

---

# Basic Bash commands
- `mkdir` stands for **Make directory** and is used to make a new directory or a folder.
- `mv` stands for **Move** and it moves one or more files or directories from one place to another. We need to specify what we want to move, i.e., the source and where we want to move them, i.e., the destination.
- `touch` command is used to create new, empty files. It is also used to change the timestamps on existing files and directories.
- `rm` stands for **Remove** and it removes files or directories. By default, it does not remove directories, but if used as `rm -r *` within a directory, then every directory and file inside that directory is deleted (`*` is a special characters that matches everything).

---

# Not all commands are equals
When executing a command, like `ls` a subprocess is created. A subprocess inherits all the environment variables from the parent process, executes the command and returns the control to the calling process.

**A subprocess cannot change the state of the calling process.**

The command `source script_file` executes the commands contained in `script_file` as if they were typed directly on the terminal. It is only used on scripts that have to change some environmental variables or define aliases or function.
Typing `. script_file` does the same.

If the environment should not be altered, use `./script_file`, instead. 

---

# Run a script
To run your brand new script you may need to change the access permissions of the file. To make a file executable run

```bash
chmod +x script_file
```

Finally, remember that the **first line of the script** tells the shell which interpreter to use while executing the file. So, for example, if your script starts with `#!/bin/bash` it will be run by `Bash`, if is starts with `#!/usr/bin/env python` it will be run by python.

---

# Built-in commands
Some commands, like `cd` are executed directly by the shell, without creating a subprocess.

Indeed it would be impossible the have `cd` as a regular command! Why?

**Answer**: a subprocess cannot change the state of the calling process, whereas `cd` needs to change the value of the environmental variable `PWD`(that contains the name of the current working directory).

---

# Other commands
In general a **command** can refer to:
  - a builtin command;
  - an executable;
  - a function.

The shell looks for executables with a given name within directories specified in the environment variable `PATH`, whereas aliases and functions are usually sourced by the `.bashrc` file (or equivalent).

To check what `command_name` is:
```bash
type command_name
```

To check its location type:
```bash
which command_name
```

---

# A warning about filenames
In order to live happily and without worries, **don't** use spaces nor accented characters in filenames!

Space characters in file names should be forbidden by law! The space is used as separation character, having it in a file name makes things a lot more complicated in any script (not just `bash` scripts).

Use underscores (snake case): `my_wonderful_file_name`, or uppercase characters (camel case): `myWonderfulFileName`, or hyphens: `my-wonderful-file-name`, or a mixture:
`myWonderful_file-name`, instead.

But **not** `my wonderful file name`. It is not wonderful at all if it has to be parsed in a script.

---

# Wildcards
A wildcard is a symbol (or set of symbols) representing other characters. It is really useful for searching a file (maybe you know just its extension) or listing a subset of files in a folder (maybe you want to display only files starting with `2023-`).

- The wildcard `?` means it will match a single character. For example, `S??` n will match anything that will begin with S and end with n and has two characters between them.
- The wildcard `*` means it will match any number of characters or a set of characters. For example, `S**n` will match anything between S and n. The number of characters between them does not count.
- The wildcard `[]` means it will match characters that are enclosed in square braces. For example, `S[on]n` will match only `Son` and `Snn`. We can also specify characters in braces like `S[a-d]n`, which will match `San`, `Sbn`, `Scn`, `Sdn`.

---

# Exercises
- Go to your home folder (*Suggestion:* you can either use `~` or `$HOME`)
- Create a folder named `test1`
- Go inside `test1` and create a directory `test2`
- Go inside `test2` and then up one directory (*Suggestion:* `..` indicates the upper directory)
- Create the following files `f1.txt`, `f2.txt`, `f3.dat`, `f4.md`, `readme.md`, `.hidden`
- List all files in the directory, also the hidden ones
- List only files with txt extension (*Suggestion:* use `*` wildcard)
- List files with `1`, `2`, `3` or `4` in the name (*Suggestion:* use `[1-4]` wildcard)
- Move the `readme.md` in `test2`
- Move all txt files in `test2` in one command
- Remove `f3.dat`
- Remove all contents of `test2` and the folder itself in one commands

---

# Download and deflate a matrix
With `wget` you can retrieve content from web servers. For instance, you can download a matrix from the matrix market with `wget https://math.nist.gov/pub/MatrixMarket2/NEP/mhd/mhd416a.mtx.gz`.
To unzip the file, simply type `gzip -dk mhd416a.mtx.gz`

---

# More commands
- `cat` stands for **Concatenate** and it reads a file and outputs its content. It can read any number of files, and hence the name concatenate.
- `wc` is short for **Word count**. It reads a list of files and generates one or more of the following statistics: newline count, word count, and byte count.
- `grep` stands for **Global regular expression print**. It searches for lines with a given string or looks for a pattern in a given input stream.
- `head` show the first lines of a file
- `tail` show the last lines of a file 
- `file` reads the files specified and performs a series of tests in attempt to classify them by type

---

# Redirection, pipelines and filters
We can add operators between commands in order to chain them together.
- The pipe operator `|`, forwards the output of one command to another. E.g. `cat /etc/passwd | grep user` checks system information about "user".
- The redirect operator `>` sends the standard output of one command to a file. E.g. `ls > files-in-this-folder.txt` saves a file with the list of files.
- The append operator `>>` appends the output of one command to a file.
- The operator `&>` sends the standard output and the standard error to file
- `&&`  pipe is activated only if the return status of the first command is 0. It is used to chain commands together: e.g. `sudo apt update && sudo apt upgrade`
- `||` pipe is activated only if the return status of first command is different from 0.
- `;` is a way to execute to commands regardless of the output status
- `$?` is a variable containing the output status of the last command

---

# Exercises
- Create a file with the current date (one command) and display its content
- Count the number of lines in the matrix `mhd416a.mtx` (*Suggestion:* use `cat`, `wc` and `|`)
- List the entries of the matrix that are smaller than 1e-10 in absolute value. You can assume that all values are in exponential format and all values are greater than 1e-100 in absolute value. Count how many entries satisfy this criteria. (*Suggestion:* use `cat`, `grep`, `wc` and `|` )

---

# Advanced commands
 - `tr` stands for **translate**. It supports a range of transformations including uppercase to lowercase, squeezing repeating characters, deleting specific characters, and basic find and replace. For instance:
     - `echo "Welcome to apsc labs" | tr [a-z] [A-Z]` converts all characters to upper case.  
     - `echo -e "A;B;c\n1,2;1,4;1,8" | tr "," "." | tr ";" ","` translates a line of a CSV in italian format to a standard format.
     - `echo "my ID is 73535" | tr -d [:digit:]` deletes all the digits from the string

---

# Advanced commands
 - `sed` stands for **stream editor** and it can perform lots of functions on file like searching, find and replace, insertion or deletion. We give just an hint of its true power
    - `echo "unix is great os. unix is open source." | sed 's/unix/linux/'` replaces the first occurrence of "unix" with "linux"
    - `echo "unix is great os. unix is open source." | sed 's/unix/linux/2'` replaces the second occurrence of "unix" with "linux"
    - `echo "unix is great os. unix is open source." | sed 's/unix/linux/g'` replaces all occurrences of "unix" with "linux"
    - `echo -e "ABC\nabc" | sed '/abc/d'` delete a line matching "abc"
    - `echo -e "1\n2\n3\n4\n5\n6\n7\n8" | sed '3,6d'` delete lines 3 to 6

---

# Advanced commands
 - `cut` is a command for cutting out the sections from each line of files and writing the result to standard output.
     - `cut -b 1-3,7- state.txt` cut bytes (`-b`) from 1 to 3 and from 7 to end of the line
     - `echo -e "A,B,C\n1.22,1.2,3\n5,6,7\n9.99999,0,0" | cut -d "," -f 1` get the first column of a CSV (`-d` specifies the delimiter among field, `-f n` specifies to pick the n-th field from each line)
 - `find` is used to find files in specified directories that meet certain conditions. For example: `find . -type d -name "*lib*"` find all directories (not files) starting from the current one (`.`) whose name contain lib.
 - `locate` is less powerful than `find` but much faster since it relies on a database that is updated on a daily base or manually using the command `updatedb`. For example: `locate -i foo` finds all files or directories whose name contains `foo` ignoring case.

---

# Quotes
Double quotes may be used to identify a string where the variables are interpreted. Single quotes identify a string where variables are not interpreted. Check the output of the following commands
```bash
a=yes
echo "$a"
echo '$a'
```
The output of a command can be converted into a string and assigned to a variable for later reuse:
```
list=`ls -l`
``` 
or
```
list=$(ls -l)
```

---

# Processes

- Launch a command and send it in the background: `./my_command &`

- `Ctrl-Z` suspends the current subprocess and `bg` reactivates the suspended subprocess in the background.

- `jobs` lists all subprocesses running in the background in the terminal.

- `fg %n` brings back to the foreground the n-th subprocess in the background.

- `Ctrl-C` terminates the subprocess in the foreground (when not trapped).

- `kill pid` sends termination signal to the subprocess with id `pid`. You can get a list of the most computationally expensive processes with `top` and a complete list with `ps aux` (usually `ps aux` is filtered through a pipe with `grep`)

All subprocesses in the background of the terminal are terminated when the terminal is closed (unless launched with `nohup`, but that is another story...)

---

# How to get help
Most commands provide a `-h` or `--help` flag to print a short help information: 
```bash
find -h
```

`man command` prints the documentation manual for command.
There is also an info facility that sometimes provides more information: `info command`.

---

<!--
_class: titlepage
_paginate: skip
-->

# Introduction to `git`.

---

# Version control
Version control, also known as source control, is the practice of tracking and managing changes to software code. Version control systems are software tools that help software teams manage changes to source code over time.

`git` is a free and open-source version control system, originally created by Linus Torvalds in 2005. Unlike older centralized version control systems such as SVN and CVS, Git is distributed: every developer has the full history of their code repository locally. This makes the initial clone of the repository slower, but subsequent operations dramatically faster.

---

# How does `git` works?

1. Create (or find) a repository with a git hosting tool (an online platform that host you project, like Github or Gitlab)
2. `clone` (download) the repository 
3. `add` a file to your local repo 
4. `commit` (save) the changes, this is a local action, the remote repository (the one in the cloud) is still unchanged
5. `push` your changes, this action synchronizes your version with the one in the hosting platform

![bg right:45% width:580](images/01_git_diagram.svg)

---

# How does `git` works? (Working in teams)

If you and your teammates work on different files the workflow is the same as before, you just have to remember to `pull` the changes that your colleagues made.

If you have to work on the same files, the best practice is to create a new `branch`, which is a particular version of the code that branches form the main one. After you have finished working on your feature you `merge` the branch into the main.


---

# Other useful `git` commands
- `diff` show the differences between your code and the last commit
- `status` list the status of all the files (e.g. which files have been changed, which are new, which are deleted and which have been added)
- `log` show the history of commits
- `checkout` switch to a specific commit or brach
- `stash` temporarily hide all the modified tracked files

---

# SSH authentication
![bg right:40% width:500px](images/01_rsa.png)

1. Register to GitHub
2. [Create the SSH key](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent?platform=linux).
3. [Add it to your account](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account)
4. Configure your machine:
```
git config --global user.name "Name Surname"
git config --global user.email "name.surname@email.com"
```

See [here](https://www.digitalocean.com/community/tutorials/understanding-the-ssh-encryption-and-connection-process) for more details on SSH. 

---

# Hands on `git`: working on different files
1. Get in groups of 2-3 students.
2. One of the members of the group creates a new repo (go to https://github.com/ and click the plus in the top right corner) and everyone clone it.
3. Everyone should create a file with its name and put it online, after everyone is done pull the latest version.

---

# Hands on `git`: working on the same file
Now try working on the same file: every one should create a hello world `main.cpp` that shows a greet with your name. To avoid conflicts:
1. create a different branch with `git checkout -b [name_of_your_new_branch]`
2. develop your code and put your branch online
3. when everyone is done merge your branch into main with the following commands
```bash
git checkout main
git pull origin main
git merge [name_of_your_new_branch]
git push origin main
```
the first one to do so will have no issue, the following will have to solve a merge conflict and commit and push your "solution" to the conflict

---

# The course repository

Clone the course repository:
```
git clone --recursive git@github.com:pcafrica/advanced_programming_2023-2024.git
```
<br>
<br>

---

<!--
_class: titlepage
_paginate: skip
-->

# **Have fun!**
