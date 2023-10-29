<!--
title: Lecture 06
paginate: true

_class: titlepage
-->

# Lecture 06
<br>

## The Standard Template Library. Evolution since C++11.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 31 Oct 2023

---

# Outline

<div class="columns">
<div>

## The Standard Template Library
- Containers
  - Sequence containers
  - Container adaptors
  - Associative containers
- Iterators
- Algorithms

</div>
<div>

## &nbsp;

- Utilities
  - Smart pointers
  - `byte`, `pair`, `tuple`, `variant`, `optional`, `any`
  - Function wrappers
  - I/O streams
  - Random numbers
  - Time measuring

</div>
</div>

---

<!--
_class: titlepage
-->

# An overview of the<br>Standard Template Library (STL) in C++

---

# History

In November 1993, Alexander Stepanov introduced the Standard Template Library (STL) to the ANSI/ISO committee for C++ standardization. This library was founded on the principles of generic programming and featured generic containers, iterators, and a comprehensive set of algorithms designed to operate on them.

The proposal was not only accepted but also paved the way for what is now known as the Standard Library. The Standard Library has evolved into a vast collection of tools that play an indispensable role in modern C++ development.

Notably, all functionalities provided by the Standard Library are encapsulated under the `std::` namespace or, in some cases, within sub-namespaces also contained within `std::`.

---

# The Boost libraries

Many components added to the Standard Library over the years were originally proposed in the [Boost C++ libraries](https://www.boost.org/), a collection of libraries designed to complement the Standard Library and cater to a wide range of applications.

Notably, one outstanding component within the Boost libraries is the [Boost Graph Library](https://www.boost.org/doc/libs/1_72_0/libs/graph/doc/index.html), widely used by professionals working with graphs and networks.

All Boost libraries are open-source and can be installed individually or as a whole on various Linux platforms using package managers. For instance, on Ubuntu, you can use the command `sudo apt-get install libboost-all-dev`. Alternatively, you can download the source code and compile them manually.

---

# An overview of the STL (1/2)

- **Porting of C libraries**: Several C libraries have been adapted to the `std` namespace. As an example, `<math.h>` becomes `<cmath>`, and they all begin with a 'c'.
- **Containers**: Generic containers and iterators.
- **Utilities**: Smart pointers, fixed-size collections of heterogeneous values like `pair` and `tuple`, clocks and timers, function wrappers, and predefined functors. Also, the `ratio` class for constant rationals.
- **Algorithms**: These operate on ranges of values, usually stored in standard containers, to perform specific actions like sorting, transformations, and copying. Some of them even support parallel execution.
- **Strings and text processing**: The `string` class and its derived classes, regular expressions, and efficient string manipulation tools.
- **Support for I/O**: I/O streams and related utilities.
- **Utilities for diagnostics**: Standard exception classes and exception handlers.

---

# An overview of the STL (2/2)

- **Numerics**: `complex<T>`, numeric limits, random numbers and distributions, and basic mathematical operators.
- **Support for generic programming**: Type traits, `declval`, and `as_const`.
- **Support for reference and move semantics**: Reference wrappers, `move()`, and `forward<T>`.
- **Support for multithreading and concurrency**: Threads, mutexes, locks, and parallel algorithms.
- **Support for internationalization**: `locale` and `wide_char`.
- **Filesystem**: Tools for examining the file system.
- **Allocators**: Utilities that allow you to change how objects are allocated within containers.
- **Utilities for hybrid data**: `optional`, `variant`, and `any`.

---

# C++20 additions

C++20 introduces some significant additions:

- **Concepts**: Constraints on template parameters to improve code quality and error messages.
- **Ranges**: A library extension for easier data manipulation and more readable code.
- **Modules**: Organize code into reusable modules, reducing compile times and header-related issues.
- **Coroutines**: Simplify asynchronous and concurrent programming for better code readability.

---

# A milestone: C++11

- **Standardization process**: C++11 marked the successful completion of a rigorous standardization process.
- **Modern features**: C++11 introduced modern language features like lambda expressions and range-based for loops.
- **Enhanced Standard Library**: New containers, algorithms, and utility classes.
- **Improved memory management**: Smart pointers were introduced in C++11.
- **Initializer lists**: C++11 introduced initializer lists, simplifying data structure initialization.
- **Simpler and safer code**: The addition of lambda expressions improved code readability and maintainability.
- **Standardized threads**: It brought a standardized threading library, enabling concurrent and parallel programming.
- **Improved performance**: Move semantics and rvalue references boosted resource management and program performance.

---

<!--
_class: titlepage
-->

# Containers

---

# Overview of containers (1/4)

Containers can be categorized based on how data is stored and handled internally. The categories include:

- **Sequence containers**: `vector<T>`, `array<T,N>`, `deque<T>`, `list<T>`, `forward_list<T>`.
  - Ordered collections of elements with their position independent of the element value.
  - In `vector` and `array`, elements are guaranteed to be contiguous in memory and can be accessed directly using the `[]` operator.

- **Adaptors**: These are built on top of other containers and provide special operations:
  - `stack<T>`, `queue<T>`, and `priority_queue<T>`.

---

# Overview of containers (2/4)

- **Associative containers**: These collections have elements whose position depends on their content. They are divided into:
  - **Maps**: Elements are key-value pairs.
  - **Sets**: Elements are just values (in sets, keys and values are considered the same).
  - Furthermore, they can be divided into **ordered** and **unordered**, depending on how the elements are stored, imposing different requirements on element types.

- *Note*: In a set, the terms "value" and "key" are used interchangeably since they are equivalent.

---

# Overview of containers (3/4)

- **Ordered associative containers**:
  - `set<K>` (no repetition) and `multiset<K>` (repetition allowed): They store single values, and the value is the key.
  - `map<K,V>` (no repetition of keys) and `multimap<K,V>` (repetition of keys allowed): They store pairs of (key, value) and act as dictionaries.
  
- An ordering relation must be defined for the key `K`. It can be done using a specific callable object, a specialization of the functor `std::less<K>`, or by defining `operator<()`.
- Keys can be accessed read-only; modifications of keys require special operations.

---

# Overview of containers (4/4)

- **Unordered associative containers**:
  - `unordered_set<K>` and `unordered_multiset<K>`.
  - `unordered_map<K,V>` and `unordered_multimap<K,V>`.

- Their general behavior is similar to that of the ordered counterparts.
- A hashing function, mapping keys to positive integers in a range [0, max), should be provided along with a proper equivalence relation among keys.
- For standard types, a default hash function is provided by the library, as well as relational operators.

---

![bg 70%](images/sequence_containers.png)

---

![bg 70%](images/associative_containers.png)

---

![bg 70%](images/special_containers.png)

---

<!--
_class: titlepage
-->

# Iterators

---

<!--
_class: titlepage
-->

# Algorithms

---

<!--
_class: titlepage
-->

# Utilities

---

# Smart pointers

---

# `byte`, `pair`, `tuple`, `variant`, `optional`, `any`

---

# Function wrappers

---

# I/O streams

---

# Random numbers

---

# Time measuring

--- 
<!--
_class: titlepage
-->

# C++14

---

<!--
_class: titlepage
-->

# C++17

---

<!--
_class: titlepage
-->

# C++20

---

# C++ 20

- Concepts
- Ranges
- Modules
- Coroutines

---

<!--
_class: titlepage
-->

# Beyond C++20

---

<!--
_class: titlepage
-->

# Best practices for utilizing the modern STL

---

# Tips for leveraging the STL effectively
- How to use the STL effectively:
  - Algorithm usage
  - Properly using containers and smart pointers
  - Incorporating newer features for cleaner and more efficient code
- Real-world examples and case studies showcasing best practices

---

# Explanations and examples: Practical tips
- Detailed insights on best practices for using the STL efficiently
- Real-world code examples demonstrating effective STL usage

---

# Case study: Evolution of a sample code
- Taking a simple code example and evolving it from C++98 to the latest C++ standard
- Comparing code complexity, readability, and performance at each stage

---

# Explanations and examples: Code evolution
- Step-by-step analysis of code evolution with detailed examples at each stage

---

<!--
_class: titlepage
-->

# Conclusion

---

# Challenges and considerations
- Potential challenges when transitioning to newer STL versions
- Compatibility issues and strategies for maintaining legacy code
- Future directions and ongoing evolution of the STL

---

# Explanations and examples: Navigating challenges
- Detailed explanations of challenges and considerations when working with evolving STL versions
- Practical strategies for addressing these challenges

---

<!--
_class: titlepage
-->

# Additional resources

---

# References and further reading
-
Provide references, books, and online resources for further learning on the STL and C++ evolution
- [Evolution since C++11](https://github.com/AnthonyCalandra/modern-cpp-features)


---

# A final recommendation

C++ is continuously evolving, and to maintain backward compatibility, new features are added while very few, if any, are eliminated. However, if you adopt a specific programming style, you'll find yourself using only a subset of what C++ has to offer.

The more outdated and cumbersome features that make programming more complex and less elegant will gradually be used less and less.

It's advisable to start incorporating the new features that genuinely assist you in writing cleaner, simpler code. Most of the features illustrated here move in that direction.

But always remember: the most important aspect of your code is whether it accomplishes the right task. An elegant code that yields incorrect results is of no use.

---

<!--
_class: titlepage
-->

# :arrow_right: ???
