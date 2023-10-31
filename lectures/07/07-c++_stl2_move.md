<!--
title: Lecture 07
paginate: true

_class: titlepage
-->

# Lecture 07
<br>

## Smart pointers, utilities, move semantics.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 07 Nov 2023

---

# Outline

1. Smart pointers
2. I/O streams
3. Random numbers
4. Exceptions
5. Other utilities
   - Time measuring
   - Filesystem
6. Move semantics

---

<!--
_class: titlepage
-->

# Smart pointers

---

# RAII: Resource Acquisition Is Initialization

RAII, short for Resource Acquisition Is Initialization, plays a significant role in C++. It essentially means that an object should be responsible for both the creation and destruction of the resources it owns.

#### Not RAII-Compliant:

```cpp
double *p = new double[10]; // Who is responsible for destroying the resources pointed to by `p`?
```

#### RAII-Compliant:

```cpp
std::array<double, 10> p; // The variable `p` takes care of creating 10 doubles and destroying them.
```

In C++, smart pointers are an important to implement RAII.

---

# Pointers in modern C++

In modern C++, we use different types of pointers:

- **Standard Pointers:** Use them only to watch (and operate on) an object (resource) whose lifespan is independent of that of the pointer (but not shorter).
- **Owning Pointers (Smart Pointers):** They control the lifespan of the resource they point to. There are three kinds:
  - `std::unique_ptr`: With unique ownership of the resource. The owned resource is destroyed when the pointer goes out of scope.
  - `std::shared_ptr`: With shared ownership of a resource. The resource is destroyed when the **last** pointer owning it is destroyed.
  - `std::weak_ptr<T>`: A non-owning pointer to a shared resource, reserved for special use cases.

Smart pointers implement the RAII concept. For simply addressing a resource, possibly polymorphically, use ordinary pointers.

---

# Example: the need for `unique_ptr` (1/4)

```cpp
class MyClass {
public:
    void set_polygon(Polygon *p) {
        polygon = p;
    }
private:
    Polygon *polygon; // Polymorphic object.
}

Polygon *create_polygon(std::string t) {
    switch (t) {
        case "Triangle":
            return new Triangle;
        case "Square":
            return new Square;
        default:
            return nullptr;
    }
}
```

---

# Example: the need for `unique_ptr` (2/4)

```cpp
MyClass a;
a.set_polygon(create_polygon("Triangle"));
```

This design is error-prone, requiring careful handling of resources, leading to potential memory leaks and dangling pointers.

---

# Example: the need for `unique_ptr` (3/4)

```cpp
class MyClass {
public:
    set_polygon(std::unique_ptr<Polygon> p) {
        polygon = std::move(p);
    }
private:
    std::unique_ptr<Polygon> polygon;
}

std::unique_ptr<Polygon> create_polygon(std::string t) {
    switch (t) {
        case "Triangle":
            return std::make_unique<Triangle>(); // 'make_unique' available since C++14.
        case "Square":
            return std::make_unique<Square>();
        default:
            return std::unique_ptr<Polygon>(); // null pointer.
    }
}
```


---

# Example: the need for `unique_ptr` (4/4)

```cpp
MyClass a;
a.set_polygon(create_polygon("Triangle"));
```

This version with `unique_ptr` is RAII-compliant, improving resource management.

---

# How a `unique_ptr` works

A `unique_ptr<T>` serves as a unique owner of the object of type `T` it refers to. The object is destroyed automatically when the `unique_ptr` gets destroyed.

It implements the `*` and `->` dereferencing operators, so it can be used as a normal pointer. However, it can be initialized to a pointer only through the constructor.

The default constructor produces an empty (null) unique pointer, and you can check if a `unique_ptr` is empty by testing `if (ptr)` or using it in a boolean context.

## Moving a `unique_ptr` around

By definition, **unique** pointers cannot be copied, but their ownership can be transferred using the `std::move` utility.

---

# Main methods and utilities of `unique_ptr`

- `std::swap(ptr1, ptr2)`: Swaps ownership.
- `ptr1 = std::move(ptr2)`: Moves resources from `ptr2` to `ptr1`. The previous resource of `ptr1` is deleted, and`ptr2` remains empty.
- `ptr.reset()`: Deletes the resource, making `ptr` empty.
- `ptr.reset(ptr2)`: Equivalent to `ptr = std::move(ptr2)`.
- `ptr.release()`: Returns a standard pointer, releasing the resource without deleting it. `ptr` becomes empty.

`unique_ptr` instances can be stored in standard containers, such as vectors.

---

# Shared pointers

While `unique_ptr` do not cause any computational overhead they are just a light wrapper around an ordinary pointer), shared pointers do, so use them only if it is really necessary.
  
For instance you have several objects that **refer** to a resource (e.g., a matrix, a shape, ...) that is build dynamically (and maybe is a polymorphic object). You want to keep track of all the references in such a way that when (and only when) the last one gets destroyed the resource is also destroyed.

To this purpose you need a `shared_ptr<T>`. It implements the semantic of *clean it up when the resource is no longer used*.

---

# Example: shared pointers

```cpp
// Create a shared_ptr to a dynamically allocated object.
std::shared_ptr<MyClass> shared_ptr = std::make_shared<MyClass>(42);

// Access the object through the shared_ptr.
shared_ptr->print();

// Create another shared_ptr that shares ownership
std::shared_ptr<MyClass> another_shared_ptr = shared_ptr;

// Check the use count (number of shared_ptrs owning the object).
std::cout << "Use count: " << shared_ptr.use_count() << std::endl;

// Create a new shared_ptr.
// The old one goes out of scope, but is still referenced by 'another_shared_ptr'.
std::shared_ptr<MyClass> new_shared_ptr = std::make_shared<MyClass>(55);
shared_ptr = new_shared_ptr;

// Check the use count again.
std::cout << "Use count: " << shared_ptr.use_count() << std::endl;
```

---

# `std::weak_ptr`

The `std::weak_ptr` is a smart pointer that holds a non-owning (*weak*) reference to an object managed by a `std::shared_ptr`. It must be converted to `std::shared_ptr` to access the referenced object.

```cpp
std::shared_ptr<int> ptr = std::make_shared(10);
std::weak_ptr<int> weak1 = ptr; // Get pointer to data without taking ownership.

ptr = std::make_shared(5); // Delete managed object, acquires new pointer.
std::weak_ptr<int> weak2 = sptr; // Get pointer to new data without taking ownership.

auto tmp = weak1.lock() // tmp is nullptr, as weak1 is expired!
auto tmp2 = weak2.lock()) // tmp2 is a new shared_ptr to new data (5).
std::cout << "weak2 value is " << *tmp2 << std::endl;
```

---

# Reference wrappers

References create aliases to existing objects and must be initialized. It's crucial to be cautious with references to temporary objects. A const reference prolongs the life of a temporary object.

Standard containers can hold only "first-class" objects, but not references. However, you can use `std::reference_wrapper` from the `<functional>` header to store objects with reference-like semantics in a container.

```cpp
int a = 10, b = 20, c = 30;

std::vector<std::reference_wrapper<int>> ref_vector = {a, b, c};

// Modify the original values through the reference wrappers.
for (std::reference_wrapper<int> ref : ref_vector) {
    ref.get() += 5;
}
```
---

<!--
_class: titlepage
-->

# I/O streams

---

# I/O streams

Input/Output (I/O) streams in C++ provide a convenient way to perform input and output operations, allowing you to work with various data sources and destinations, such as files, standard input/output, strings, and more. C++ I/O streams are part of the Standard Library (STL) and are based on the concept of streams. The key components of C++ I/O streams are `iostream`, `ifstream`, `ofstream`, and `stringstream`.

- **`iostream`**: The base class for input and output streams. It is derived from `istream` (for input) and `ostream` (for output). It is used for interacting with the standard input and output streams.
  ```cpp
  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;
  std::cout << "You entered: " << number << std::endl;
  ```
    
---

# `std::ifstream`

**`std::ifstream`**: This class is used for reading data from files. You can open a file for input and read data from it.
  ```cpp
  std::ifstream file("example.txt");
  if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) {
        std::cout << line << std::endl;
      }
      file.close();
  } else {
      std::cerr << "Failed to open the file." << std::endl;
  }
  ```

---

# `std::ofstream`

**`std::ofstream`**: This class is used for writing data to files. You can open a file for output and write data to it.
  ```cpp
  std::ofstream file("output.txt");
  if (file.is_open()) {
      file << "Hello, World!" << std::endl;
      file.close();
  } else {
      std::cerr << "Failed to open the file." << std::endl;
  }
  ```

---

# `std::stringstream`

**`std::stringstream`**: This class allows you to work with strings as if they were input and output streams. You can use stringstream for parsing and formatting strings.
  ```cpp
  // Using std::stringstream to format data into a string.
  std::stringstream ss;
  const int num = 42;
  const double pi = 3.14159265359;
    
  ss << "The answer is: " << num << ", and Pi is approximately " << pi;

  std::cout << ss.str() << std::endl;

  // Parsing data from a string using std::stringstream.
  std::string input = "123 45.67";
  int parsed_int;
  double parsed_double;

  std::stringstream(input) >> parsed_int >> parsed_double;
  ```

---

# I/O formatting

**Formatting**: I/O streams provide various formatting options to control the appearance of output. For instance, `std::setw`, `std::setprecision`, `std::setfill`, etc., from the `<iomanip>` header, allow setting field width, precision, and fill characters in the output.

```cpp
const double pi = 3.14159265359;
std::cout << "Default: " << pi << std::endl;
std::cout << "Fixed with 2 decimal places: " << std::fixed << std::setprecision(2) << pi << std::endl;
std::cout << "Scientific notation: " << std::scientific << pi << std::endl;
std::cout << "Width 10 with left alignment: " << std::left << std::setw(10) << pi << std::endl;
std::cout << "Width 10 with right alignment: " << std::right << std::setw(10) << pi << std::endl;
```

**Output:**
```bash
Default: 3.14159
Fixed with 2 decimal places: 3.14
Scientific notation: 3.141593e+00
Width 10 with left alignment: 3.14159   
Width 10 with right alignment:    3.14159
```

---

<!--
_class: titlepage
-->

# Random numbers

---

# Random numbers

The capability of generating random numbers is essential not only for statistical purposes but also for internet communications. But an algorithm is deterministic. However, several techniques have been developed to generate pseudo-random numbers. They are not really random, but they show a low level of auto-correlation.

---

# C++ support for statistical distributions

C++ provides extensive support for (pseudo) random number generators and univariate statistical distributions. You need the header `<random>`. The chosen design is based on two types of objects:

1. **Engines**: They serve as a stateful source of randomness, providing random unsigned integer values uniformly distributed in a range. They are normally used with distributions.
2. **Distributions**: They specify how values generated by the engine have to be transformed to generate a sequence with prescribed statistical properties. The design separates the (pseudo) random number generators from their use to generate a specific distribution.

---

# Engines

Random number engines generate pseudo-random numbers using seed data as an entropy source. Several different classes of pseudo-random number generation algorithms are implemented as templates that can be customized. Some basic engines include:

- `linear_congruential_engine`: Linear congruential algorithm
- `mersenne_twister_engine`: Mersenne twister algorithm
- `subtract_with_carry_engine`: Subtract-with-carry algorithm (a lagged Fibonacci)

For simplicity, the library provides predefined engines, such as `default_random_engine`, which balances efficiency and quality. There are also non-deterministic engines, like `random_device`, which generate non-deterministic random numbers based on hardware data.

---

# Predefined engines

The main predefined engine is `default_random_engine`, but there are others like `minstd_rand0`, `minstd_rand`, `mt19937`, and more. You can use these engines to generate pseudo-random numbers with varying properties.

## How to use a predefined engine

Using a predefined engine is simple. You can generate an object of the chosen class either with the default constructor or by providing a seed (an unsigned integer). If you use the same seed, the sequence of pseudo-random numbers will be the same every time you execute the program.

```cpp
std::default_random_engine rd1;
std::default_random_engine rd2{1566770}; // With a seed.
```

Remember, random engines should always be used together with distributions.

---

# Distributions

Distributions are template classes that implement a call operator `()` to transform a random sequence into a specific distribution. You need to pass a random engine to the distribution to generate numbers according to the desired distribution. For example:

```cpp
std::default_random_engine gen;
std::uniform_int_distribution<> dice{1, 6};
for (int n = 0; n < 10; ++n)
    std::cout << dice(gen) << ' ';
std::cout << std::endl;
```

Here, `uniform_int_distribution` provides an integer uniform distribution in the range (1, 6).

---

# How to use the `random_device`

The `random_device` provides non-deterministic random numbers based on hardware data. However, it is slower than other engines and is often used to generate the seed for another random engine. Here's how to use it:

```cpp
std::random_device rd;
std::knuth_b reng{rd()};
// ...
```

The `knuth_b` engine is initialized with a seed generated by the `random_device`.

---

# `seed_seq`

The utility `std::seed_seq` consumes a sequence of integer-valued data and produces a requested number of unsigned integer values. It provides a way to seed multiple random engines or generators that require a lot of entropy. For example:

```cpp
std::seed_seq seq = {1, 2, 3, 4, 5};
std::vector<std::uint32_t> seeds(10);
seq.generate(seeds.begin(), seeds.end());
```

You can use the generated seeds to feed different random engines.

---

# Shuffling

In C++, you can shuffle a range of elements using the `shuffle` utility from the `<algorithm>` header. It shuffles the elements randomly so that each possible permutation has the same probability of appearance. Here's an example:

```cpp
std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::random_device rd;
std::default_random_engine g{rd()};
std::shuffle(v.begin(), v.end(), g);
```

Every time you run this code, the vector `v` will be shuffled differently.

---

# Sampling

Another useful utility in `<algorithm>` is `sample`, which extracts `n` elements from a range without repetition and inserts them into another range. Here's an example:

```cpp
int n = 10;
std::vector<double> p;
// Fill p with more than n values to sample.
std::vector<double> res;
auto seed = std::random_device{}();
std::sample(p.begin(), p.end(), std::back_inserter(res), n, std::mt19937{seed});
```

This code generates a different realization of the sample every time you run it.

---

<!--
_class: titlepage
-->

# Exceptions

---

# Preconditions, postconditions, and invariants

In software development, a function (or method) can be seen as a mapping from input data to output data. The software developer specifies the conditions under which the input data is considered valid; this specification is called a **precondition**. The developer also guarantees that the expected output, called a **postcondition**, is provided when the input adheres to the precondition. Failure to meet these conditions is considered a **fault** or **bug** in the code.

An **invariant** of a class is a condition that must be satisfied by the state of an object at any point in time, except for transient situations like the object's construction process. An object is considered to be in an **inconsistent state** if the invariants are not met.

The verification of preconditions, postconditions, and invariants is an integral part of **code verification** during the development phase.

---

# An example

Consider a function in C++:

```cpp
Matrix cholesky(const Matrix& m);
```

- This function has a **precondition** that requires the input matrix `m` to be symmetric positive definite.
- The **postcondition** is that the output matrix is a lower triangular matrix representing the Cholesky factorization of `m`.
- An invariant of a symmetric matrix `m` is that `m(i,j) = m(j,i)` for all matrix elements.

---

# Exceptions

An **exception** is an anomalous condition that disrupts the normal flow of a program's execution when left unhandled. It is not the result of incorrect coding but rather arises from challenging or unpredictable circumstances.

Examples of exceptions include running out of memory after a `new` operation, failing to open a file due to insufficient privileges, or encountering an invalid floating-point operation (floating-point exception or FPE) that cannot be easily predicted.

It's essential to note that an **incorrect behavior** (e.g., failure to meet a postcondition for correct input data) stemming from incorrect coding is **not** an exception; it is a bug that should be debugged.

---

# Why handling exceptions

Historically, in scientific computing, exceptions were often not handled at all or led to program termination with an error message. However, the rise of graphical interfaces and more complex software systems has made exception handling more critical. An algorithm's failure should not lead to the termination of the entire program. There is a growing need to perform *recovery* operations when exceptions occur.

---

# Floating point exceptions

It's important to note that **floating point exceptions** (FPE) are a special type of exception. In IEEE-compliant architectures, invalid arithmetic operations on floating-point numbers do not result in program failure. Instead, they produce special numerical values like `inf` (infinity) or `nan` (not-a-number), and the operations continue.

This unique behavior distinguishes floating point exceptions from traditional exceptions. There are ways, not covered in this course, to properly handle FPEs.

---

# Exception handling in C++

C++ provides an effective mechanism to handle exceptions. The basic structure consists of:

- Using the `throw` command to indicate that an exception has occurred. You can throw an object containing information about the exception.

- Employing the `try{} catch(){}` blocks to catch and handle exceptions. If an exception is not caught, it will propagate up the call stack and might lead to program termination.

The `try` block contains the code that might throw an exception, while the `catch` block handles the exception.

---

# Standard exceptions

The Standard Library in C++ provides predefined **exception classes** accessible through the `<exception>` header. These classes derive from `std::exception`, which defines a method `what()` to return an exception message.

```cpp
virtual char const * what() const noexcept;
```

Standard exceptions can be used directly or derived from to create custom exceptions. Using standard exceptions or derived classes is recommended for consistent error handling.

---

# Standard exceptions

Standard exceptions in C++ are part of the C++ Standard Library and provide predefined classes for handling different types of exceptions. These classes are useful for consistent and standardized error handling. Here's an overview of some common standard exceptions:

Remember that these standard exceptions are designed to be used or derived from when creating your own exceptions. This promotes consistency and helps others understand your error handling approach.

---

# An overview of standard exceptions

- **std::exception**: The base class for all standard exceptions. It provides a `what()` method to retrieve an error message.
- **std::runtime_error**: Represents runtime errors.
- **std::logic_error**: Represents logical errors in the program. It includes exceptions like `std::invalid_argument` and `std::domain_error`.
- **std::overflow_error**: Indicates arithmetic overflow errors.
- **std::underflow_error**: Indicates arithmetic underflow errors.
- **std::range_error**: Indicates errors related to out-of-range values.
- **std::bad_alloc**: Used to indicate memory allocation errors.
- **std::bad_cast**: Indicates casting errors during runtime type identification (RTTI).
- **std::bad_typeid**: Used for errors related to the type identification of objects.
- **std::bad_exception**: A placeholder for all unhandled exceptions.

---

# Example: custom exception handling in C++ (1/2)

```cpp
class MyException : public std::exception {
public:
    MyException(const char* message) : msg(message) {}

    // Override the what() method to provide an error message
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};

int divide_positive(int num, int den) {
    if (num <= 0) {
        throw std::range_error{"Numerator out-of-range"};
    }

    if (den == 0) {
        throw MyException{"Division by zero not allowed."};
    }

    return = num / den;
}
```

---

# Example: custom exception handling in C++ (2/2)

```cpp
try {
    const int result1 = divide_positive(6, 2);  // Ok.
    const int result2 = divide_positive(-4, 2); // Throw std::range_error.
    const int result3 = divide_positive(2, 0);  // Throw MyException.
}
catch (const MyException& exc) {
    std::cerr << "Custom exception caught: " << exc.what() << std::endl;
}
catch (const std::range_error& exc) {
    std::cerr << "Range exception caught: " << exc.what() << std::endl;
}
catch (...) {
    std::cerr << "Unknown exception caught." << std::endl;
}
```

---

# Old-style error control

In situations where an algorithm's failure is one of its expected outcomes (e.g., the failure of convergence in an iterative method), returning a **status** rather than throwing an exception may be more suitable. Instead of terminating the program, a status variable is used to indicate the outcome, which can be checked by the caller.

## Some comments

Exception handling is increasingly important in code that must be integrated into a broader workflow or graphical interface. However, it's worth noting that the `try-catch` mechanism introduces some inefficiencies since it checks for exceptions every time a function is called. High-performance code often minimizes the use of exception handling.

In practical contexts where exception handling is necessary, the `noexcept` declaration can help optimize efficiency by indicating functions and methods that do not throw exceptions.

---

<!--
_class: titlepage
-->

# Other utilities

---

# Time measuring

C++ provides three common clocks:

- **`std::chrono::system_clock`**: Represents the system-wide real-time clock. It's suitable for measuring absolute time.
- **`std::chrono::steady_clock`**: Represents a steady clock that never goes backward. It's suitable for measuring time intervals and performance measurements.
- **`std::chrono::high_resolution_clock`**: Represents a high-resolution clock with the smallest possible tick duration. It's often used for precise timing.

---

# Example: time measuring

```cpp
void my_function() {
    // Code to measure.
}

auto start = std::chrono::high_resolution_clock::now();
my_function();
auto end = std::chrono::high_resolution_clock::now();

auto duration =
    std::chrono::duration_cast<std::chrono::microseconds>(end - start);

std::cout << "Time taken by function: "
          << duration.count() << " microseconds" << std::endl;
```

---

# Example: benchmarking

```cpp
void my_function() {
    // Code to measure.
}

const int num_iterations = 1000;

auto start = std::chrono::high_resolution_clock::now();
for (int i = 0; i < num_iterations; ++i) {
    my_function();

}
auto end = std::chrono::high_resolution_clock::now();

auto duration =
  std::chrono::duration_cast<std::chrono::microseconds>(end - start);

std::cout << "Average time taken by function: "
          << duration.count() / num_iterations << " microseconds" << std::endl;
```

---

# Filesystem

Since C++17, a full set of utilities to manipulate files, directories, etc. in a filesystem is available.

```cpp
const auto big_file_path{"big/file/to/copy"};

if (std::filesystem::exists(big_file_path)) {
  const auto big_file_size {std::filesystem::file_size(big_file_path)};

  std::filesystem::path tmp_path{"/tmp"};
  
  if (std::filesystem::space(tmp_path).available > big_file_size) {
    std::filesystem::create_directory(tmp_path.append("example"));
    std::filesystem::copy_file(big_file_path, tmp_path.append("new_file"));
  }
}
```

---

<!--
_class: titlepage
-->

# Move semantics

---

# Conclusion

The STL is a fundamental part of the C++ standard library, offering a rich set of data structures, algorithms, and utilities that make C++ a powerful and expressive language. To fully harness the power of the STL:

1. **Algorithm usage**: Algorithms are the backbone of the STL. Utilize them to simplify and optimize common operations, enhancing code readability and maintainability.
2. **Container selection**: Choose the appropriate container type (e.g., `std::vector`, `std::map`, `std::queue`) based on your specific needs. This decision greatly impacts your code's efficiency.
3. **Smart pointers**: Smart pointers like `std::shared_ptr` and `std::unique_ptr` are crucial for effective memory management, preventing memory leaks and resource leaks.
4. **Newer features**: Stay up-to-date with the latest C++ standards (e.g., C++20, C++23) and incorporate new features like ranges, concepts, and structured bindings to write cleaner and more efficient code.

---

<!--
_class: titlepage
-->

# :arrow_right: ???
