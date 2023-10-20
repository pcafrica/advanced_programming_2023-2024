<!--
title: Lecture 05
paginate: true

_class: titlepage
-->

# Lecture 05
<br>

## Functions. Templates and generic programming in C++.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 24 Oct 2023

---

# Outline

1. Advanced topics on functions
   - Function pointers
   - Functors (function objects)
   - Lambda functions
   - Function wrappers (`std::function`)
2. Generic programming and templates
   - Generic programming
   - Function templates
   - Class templates
   - Advanced template techniques and concepts

---

<!--
_class: titlepage
-->

# Advanced topics on functions

---

# Functions in C++

In C++, functions are categorized as free functions or member functions (methods) of a class. Subcategories exist for normal functions and template functions, including automatic return functions.

For a free, non-template function, the typical declaration syntax is as follows:

```cpp
return_type function_name(...);

auto function_name(...) -> return_type;

auto function_name(...);
```

The first two forms are essentially equivalent, so choose the one that suits your preference. In the third scenario, the compiler deduces the return type, which will be explained in more detail later.

---

# Function names and function identifiers

A function is **identified** by:

- Its **name**, `fun` in the previous examples. More precisely, its **fully qualified name**, which includes the namespace, for instance `std::transform`.
- The number and type of its **parameters**.
- The presence of the `const` qualifier (for methods).
- The type of the enclosing class (for methods).

Two functions with different identifiers are eventually treated as **different functions**, which is the key for **function overloading**.

**:warning: The return type is NOT part of the function identifier!**

---

# Why use free functions

A function represents a mapping from input data (via its arguments) to an output provided through the returned value or, in some cases, through an argument if the corresponding parameter is a non-const reference.

As a result, a free function is typically **stateless**, meaning that two different calls to a function with the same input will yield the same output. The only exception to this rule is when a local variable is declared `static`.

Hence, you typically implement a function when your requirement is indeed a straightforward input/output mapping, akin to the standard mathematical definition of a function, $f: U \rightarrow V$.

---

# What type does a function return

In rare instances, a function returns a reference to an object passed by reference. This is usually done when concatenation is desired, with the streaming operator being a typical example.

```cpp
std::ostream &operator<<(std::ostream &os, const MyClass &obj)
{
  // ...
  return os; // Return the stream.
}
```

This enables concatenation like so:

```cpp
std::cout << x << " concatenated with " << y;
```

---

# Default parameters

In the **declaration** of a function, you can provide default values for the rightmost parameters.

```cpp
std::vector<double> cross_prod(const std::vector<double> &a,
                               const std::vector<double> &b,
                               const unsigned int ndim = 2);
```

For instance:

```cpp
a = cross_prod(c, d); // This sets ndim to 2.
```

---

# A recall of function overloading

```cpp
int fun(int i);
double fun(const double &z);
// double fun(double y); // Error: ambiguous!
....
auto x = fun(1);       // Calls fun(int).
auto y = fun(1.0);     // Calls fun(const double &).
```

The function that gives the best match of the argument types is chosen. Beware of possible ambiguities and implicit conversions!

---

# Callable objects

A callable object refers to an object that can be called as if it were a function, i.e., using the function call operator `operator()`. Callable objects include:

- **Functions** (free functions or member functions).
- **Function pointers**.
- **Member function pointers**: These allow you to call member functions of a class.
- **Functors (function objects)**: Instances of classes that overload `operator()`.
- **Lambda functions**: Introduced in C++11, they are useful for short, local functions.

---

<!--
_class: titlepage
-->

# Function pointers

---

# Pointers to functions

```cpp
double integrand(double x);

// Pointer to a function taking a double as an input and returning a double.
using f_ptr = double (*)(double);
// Or: typedef double (*f_ptr)(double);
double integrate(double a, double b, const f_ptr fun, unsigned n);

double I = integrate(0, 3.1415, integrand); // Passing function as a pointer.

f_ptr my_sin = std::sin; // Assigning a function pointer.

I = integrate(0, 3.1415, my_sin);
```

The name of the function is interpreted as a pointer to that function. However, you may precede it by `&`: `f_ptr f = &integrand`.

We will see in a while a safer and more general alternative to function pointers, the function wrapper `std::function` of the STL.

---

# Dynamic function selection

You can use function pointers to select and call functions at runtime based on user input or other conditions.

```cpp
int Add(int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }

int main() {
    int (*operation)(int, int); // 'operation' is a function pointer.

    if (user_input == "add") {
        operation = Add;
    } else {
        operation = Subtract;
    }

    const int result = operation(10, 5);  // Calls either Add or Subtract based on user input.

    return 0;
}
```

---

# Member function pointers

```cpp
std::vector<Shape*> shapes;
shapes.push_back(new Circle(3.0));
shapes.push_back(new Rectangle(2.0, 4.0));
shapes.push_back(new Circle(2.5));

// Define a member function pointer for the area function.
double (Shape::*area_fun)() const = &Shape::area;

for (const auto shape : shapes) {
    const double area = (shape->*area_fun)();
    std::cout << "Area: " << area << std::endl;
}

// Cleanup allocated objects.
for (auto shape : shapes) {
    delete shape;
}
```

---

<!--
_class: titlepage
-->

# Functors (function objects)

---

# Functors (Function Object)

A **function object** or **functor** is a class object which overloads the **call operator** (`operator()`). It has semantics very similar to that of a function:

```cpp
class Cube {
public:
  double operator()(double const &x) const { return x * x * x; }
};

Cube cube{}; // A function object.
auto y = cube(3.4); // Calls Cube::operator()(3.4).
auto z = Cube{}(8.0); // I create the functor on the fly.
```

If the call operator returns a `bool`, the function object is a **predicate**. If a call to the call operator does not change the data members of the object, you should declare `operator()` as `const` (as with any other method).

---

# Why functors?

**A characteristic of a functor is that it may have a state**, so it can store additional information to be used to calculate the result.

```cpp
class Calculator {
public:
    int result = 0;
};

class Add {
public:
    Calculator& calc;
    Add(Calculator& c) : calc(c) {}
    void operator()(int x, int y) { calc.result = x + y; }
};

Calculator calc;
Calculator::Add add(calc);
add(5, 3); // Result is stored in calc.result;
```

---

# Predefined functors in the Standard Template Library

Under the header `<functional>`, you find a lot of predefined functors.

```cpp
std::vector<int> i = {1, 2, 3, 4, 5};

std::vector<int> j;

std::transform(i.begin(), i.end(),    // Source.
               std::back_inserter(j), // Destination.
               std::negate<int>());

const double prod = std::accumulate(i.begin(), i.end(), 1.0, std::multiplies<int>());
```

Now `j = {-1, -2, -3, -4, -5}.`.

`std::negate<type>` is a **unary functor** provided by the standard library.

`std::back_inserter<type>` inserts the transformed elements at the end (back) of vector `j`.

---

# Some predefined functors in the STL

| Functor           | Description                      |
|-------------------|----------------------------------|
| `plus<T>`, `minus<T>` | Addition/Subtraction (Binary) |
| `multiplies<T>`, `divides<T>` | Multiplication/Division (Binary)          |
| `modulus<T>`      | Modulus (Unary)                  |
| `negate<T>`       | Negative (Unary)                 |
| `equal_to<T>`, `not_equal_to<T>` | (Non-)Equality Comparison (Binary)     |
| `greater`, `less`, `greater_equal`, `less_equal` | Comparison (Binary) |
| `logical_and<T>`, `logical_or<T>`, `logical_not<T>` | Logical AND/OR/NOT (Binary)             |

For a full list, have a look at [this web page](https://cplusplus.com/reference/functional/).

---

<!--
_class: titlepage
-->

# Lambda functions

---

# Lambda expressions

We have a very powerful syntax to create short (and inlined) functions quickly: the lambda expressions (also called lambda functions or simply lambdas). They are similar to Matlab anonymous functions, like `f = @(x) x^2`.

```cpp
auto f = [] (double x) { return 3 * x; }; // f is a lambda function.

auto y = f(9.0); // y is equal to 27.0
```

Note that I did not need to specify the return type in this case, the compiler deduces it as `decltype(3 * x)`, which returns `double`.

---

# Capture specification

The capture specification allows you to use variables in the enclosing scope inside the lambda, either by value (a local copy is made) or by reference.

- `[]`: Captures nothing
- `[&]`: Captures all variables by reference
- `[=]`: Captures all variables by making a copy
- `[=, &foo]`: Captures any referenced variable by making a copy, but capture variable `foo` by reference
- `[bar]`: Captures only `bar` by making a copy
- `[this]`: Captures the `this` pointer of the enclosing class object
- `[*this]`: Captures a copy of the enclosing class object

---

# An example of use of `[this]`

With `[this]`, we get the `this` pointer to the calling object:

```cpp
class MyClass {
public:
    void compute() const {
        auto prod = [this](double a) { x *= a; };
        std::for_each(v.begin(), v.end(), prod);
    }
private:
    double x = 1.0;
    std::vector<double> v;
};

MyClass c;
double res = c.compute();
```

Here, `compute()` uses the lambda `prod` that **changes** the member `x`. To be more explicit, you can write `this->x *= a;`.

---

<!--
_class: titlepage
-->

# Function wrappers

---

# Function wrappers

And now the **catch all function wrapper**. The class `std::function<>` declared in `<functional>` provides polymorphic wrappers that generalize the notion of a function pointer. It allows you to use any **callable object** as **first-class objects**.

```cpp
int add(int a, int b) {
    return a + b;
}

std::function<int(int, int)> func = add;

const int result = func(2, 3);
```

Function wrappers are **very useful** when you want to have a common interface to callable objects.

**Function wrappers introduce a little overhead**, since the callable object is stored internally as a pointer, but they are extremely flexible, and often the overhead is negligible.

---

# Function wrappers and polymorphism

```cpp
class Shape {
public:
    virtual double area() const = 0;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}
    double area() const override { return 3.14159265359 * radius * radius; }
private:
    double radius;
};

auto compute_area = [](const Shape& s) { return s.area(); };
// 'auto' here resolves to std::function<double(const Shape&)>.

Circle circle(5.0);
std::cout << "Circle area: " << compute_area(circle) << std::endl;
```

---

# A vector of functions

`std::function` can wrap any kind of **callable** object.

```cpp
int func(int, int); // A function.

class F2 { // A functor.
public:
    int operator()(int, int) const;
}

// A vector of functions.
std::vector<std::function<int(int, int)>> tasks;
tasks.push_back(func); // Wraps a function.
tasks.push_back(F2{}); // Wraps a functor.
tasks.push_back([](int x, int y){ return x * y; }); // Wraps a lambda.

for (auto i : tasks)
    std::cout << i(3, 4) << endl;
```

It prints the result of `func(3, 4)`, `F2{}(3, 4)`, and `12` ($3 \times 4$).

---

# `std::bind` and function adapters

```cpp
int add(int a, int b) {
    return a + b;
}

// Create a new function based on 'add' where argument 1 is set equal to 5.
std::function<int(int)> add5 = std::bind(add, 5, std::placeholders::_1);
const int result = add5(3);
```

---

<!--
_class: titlepage
-->

# Generic programming and templates

---

<!--
_class: titlepage
-->

# Generic programming

---

# What is generic programming?

- Generic programming is a programming paradigm that aims to write code in a way that's independent of data types.
- It focuses on creating reusable and versatile code by using templates or type abstractions.
- The goal is to develop algorithms and data structures that work with various data types.

---

# Why use generic programming?

- **Reusability:** Write code once, use it with multiple data types.
- **Type Safety:** Ensures that type-related errors are caught at compile-time.
- **Performance:** Optimized code for specific data types without code duplication.
- **Expressiveness:** Code that's concise and easier to read and maintain.

---

# Examples of generic programming

- **STL (Standard Template Library):** Offers a collection of generic data structures and algorithms.
- **Function templates:** Write functions that work with various data types.
- **Class templates:** Create versatile, type-safe data structures.

---

# Use cases of generic programming

1. **Containers:** Generic data structures like vectors, stacks, and queues.
2. **Algorithms:** Generic sorting, searching, and transformation algorithms.
3. **Math operations:** Functions for arithmetic operations that work with multiple numeric types.
4. **Custom data structures:** Building generic trees, graphs, or linked lists.

---

# Benefits of generic programming

- **Code reusability:** Reduced need to write similar code for different data types.
- **Type safety:** Compile-time checks to ensure type correctness.
- **Efficiency:** Optimized code for specific data types.
- **Readability:** Cleaner and more expressive code.

---

# Challenges of generic programming

- **Complexity:** Generic code may be more complex due to abstraction.
- **Compile-time overhead:** Template instantiation can lead to longer compile times.
- **Debugging:** Template error messages can be challenging to decipher.

---

# Generic programming in practice

- C++ is a language known for its strong support of generic programming.
- The Standard Template Library (STL) is a prime example of generic programming in action.
- Use of function templates and class templates in various C++ libraries and frameworks.

---

<!--
_class: titlepage
-->

# Function templates

---

# What are function templates?

- Function templates are a feature in C++ that allows you to define generic functions.
- They enable you to write a function once and use it with different data types.
- Function templates are defined using the `template` keyword, followed by type parameters enclosed in angle brackets.

## Example

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

---

# Advantages of function templates

- Code reusability: Write a single function that works with multiple data types.
- Type safety: Compiler ensures type consistency.
- Reduces code duplication.

---

# Creating and using function templates

1. Function template declaration

```cpp
template <typename T>
T add(T a, T b);
```

2. Function template instantiation

```cpp
int result = add(5, 3);      // T is deduced as int
double result2 = add(2.5, 3.7); // T is deduced as double
```

---

# Examples of function templates

## Generic functions

```cpp
template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}
```

## Template specialization

```cpp
template <>
char max(char a, char b) {
    return std::toupper(a) > std::toupper(b) ? a : b;
}
```

---

# Best practices and common use cases

- Use descriptive type parameter names.
- Avoid unnecessary template code duplication.
- Template functions for mathematical operations.

---

# Example: Vector sum using function template

```cpp
template <typename T>
T vectorSum(const std::vector<T>& vec) {
    T sum = T();  // Initialize sum based on type
    for (const T& elem : vec) {
        sum += elem;
    }
    return sum;
}
```

---

<!--
_class: titlepage
-->

# Class templates

---

# Introduction to class templates

- Class templates allow you to define generic classes.
- Syntax: `template <typename T> class ClassName { /* class members */ }`
- Type parameterization enables the class to work with different data types.

---

# Advantages of class templates

- Encapsulation of data and behavior for a specific data type.
- Code reusability: Define a class structure once and use it with various types.
- Type safety: Prevents mixing incompatible types.

---

# Creating and using class templates

1. Class template declaration

```cpp
template <typename T>
class Stack {
public:
    // Class members using type T
};
```

2. Class template instantiation

```cpp
Stack<int> intStack;        // T is int
Stack<double> doubleStack;  // T is double
```

---

# Examples of class templates

## Generic data structures (containers)

```cpp
template <typename T>
class Vector {
    // Implementation of a dynamic array for type T
};
```

## Template specialization for classes

```cpp
template <>
class Vector<std::string> {
    // Specialized behavior for strings
};
```

---

# Best practices and common use cases

- Define meaningful class names and method names.
- Use class templates for generic data structures.
- Leverage template specialization for customized behavior.

---

# Example: Templated stack class

```cpp
template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& value) {
        elements.push_back(value);
    }

    T pop() {
        if (elements.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        T top = elements.back();
        elements.pop_back();
        return top;
    }
}
```

---

<!--
_class: titlepage
-->

# Advanced template techniques and concepts

---

# Template metaprogramming

- Template metaprogramming is a way to perform computations at compile time.
- It involves using template features to generate code during compilation.
- Common use cases: constant expressions, type traits, and generic algorithms.

## Example: Compile-time Fibonacci

```cpp
template <int N>
struct Fibonacci {
    static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
    static const int value = 0;
};

template <>
struct Fibonacci<1> {
    static const int value = 1;
}
```

---

# Variadic templates

- Variadic templates allow functions and classes to accept a variable number of arguments.
- The `...` syntax is used to define variadic templates.
- Useful for handling functions with multiple arguments of varying types.

## Example: Recursive sum function

```cpp
template <typename T>
T sum(T value) {
    return value;
}

template <typename T, typename... Args>
T sum(T first, Args... rest) {
    return first + sum(rest...); // Recursively sum the arguments
}
```

---

# Template specialization and partial specialization

- Template specialization allows you to define different behavior for specific template arguments.
- Partial specialization refines specialized behavior for specific subsets of template arguments.

```cpp
template <typename T>
void process(T value) { /* Generic implementation */ }

template <>
void process<int>(int value) { /* Specialized behavior for int */ }
```

---

# SFINAE (Substitution failure is not an error)

- SFINAE is a C++ rule that allows you to enable or disable function templates based on the validity of their substitutions.
- Used for type traits and selective function overloading.

## Example: Type traits with SFINAE

```cpp
template <typename T>
struct has_member_foo {
    template <typename U>
    static std::true_type test(decltype(U::foo)*);

    template <typename U>
    static std::false_type test(...);

    static constexpr bool value = decltype(test<T>(0))::value;
};

struct MyType {
    void foo() {}
}

int main() {
    std::cout << std::boolalpha;
    std::cout << has_member_foo<MyType>::value << std::endl;  // true
    std::cout << has_member_foo<int>::value << std::endl;      // false
}
```

---

# CRTP (Curiously recurring template pattern)

- CRTP is a design pattern where a derived class inherits from a base class template with itself as the template argument.
- Used to achieve static polymorphism and code reuse.

## Example: CRTP for static polymorphism

```cpp
template <typename Derived>
class Shape {
public:
    void draw() {
        static_cast<Derived*>(this)->drawImpl();
    }
}

class Circle : public Shape<Circle> {
public:
    void drawImpl() {
        // Draw a circle
    }
}

class Square : public Shape<Square> {
public:
    void drawImpl() {
        // Draw a square
    }
}
```

---

# Traits classes and policy-based design

- Traits classes are used to encapsulate properties and behaviors of types.
- Policy-based design involves creating classes or functions with interchangeable policies to customize behavior.

## Example: Traits for type information

```cpp
template <typename T>
struct TypeTraits {
    static constexpr bool is_integral = std::is_integral<T>::value;
    static constexpr bool is_floating_point = std::is_floating_point<T>::value;
    static constexpr bool is_pointer = std::is_pointer<T>::value;
}

template <typename T>
void processType(T value) {
    if (TypeTraits<T>::is_integral) {
        // Process integral types
    } else if (TypeTraits<T>::is_floating_point) {
        // Process floating-point types
    } else {
        // Default behavior
    }
}
```

---

# Template template parameters

- Template template parameters allow you to define templates as template arguments.
- Used for defining higher-order templates that accept template classes.

## Example: Template template parameter for containers

```cpp
template <template <typename> class Container>
void processContainer(Container<int>& c) {
    // Process the container of integers
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    processContainer(vec);  // Calls processContainer for a vector of integers
}
```

---

# Type deduction and the `auto` keyword

- Type deduction allows the compiler to determine the data type of variables and return values automatically.
- The `auto` keyword simplifies code and improves readability.

```cpp
auto result = add(5, 3); // Compiler deduces result's type as int
```

---

# TODO

- integral constants
- template alias
- the use of `this` in templates
- code organization / explicit instantiation

---

<!--
_class: titlepage
-->

# :arrow_right: The Standard Template Library. New features of C++14/17/20.
