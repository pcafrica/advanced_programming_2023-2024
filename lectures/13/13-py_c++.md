<!--
title: Lecture 13
paginate: true

_class: titlepage
-->

# Lecture 13
<br>

## Integrating C++ and Python codes.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 19 Dec 2023

---

# Outline

1. Integrating C++ and Python

2. pybind11
   - Installation
   - Basics
   - Binding object-oriented code

3. Building

3. Examples

Part of these lecture notes and examples is re-adapted from [the official pybind11 documentation](https://github.com/pybind/pybind11/tree/master/docs) ([license](LICENSE_pybind11.md)) and from [this repository](https://github.com/tdegeus/pybind11_examples) ([license](LICENSE_pybind11_examples.md)).

---

<!--
_class: titlepage
-->

# Integrating C++ and Python

---

# Why integrating C++ and Python code

C++ and Python are powerful in their own right, but they excel in different areas. C++ is renowned for its performance and control over system resources, making it ideal for CPU-intensive tasks and systems programming. Python, on the other hand, is celebrated for its simplicity, readability, and vast ecosystem of libraries, especially in data science, machine learning, and web development.

- In research areas like machine learning, scientific computing, and data analysis, the need for processing speed and efficient resource management is critical.
- The industry often requires solutions that are both efficient and rapidly developed.

By integrating C++ with Python, you can create applications that harness the raw power of C++ and the versatility and ease-of-use of Python. Python, despite its popularity in these fields, often falls short in terms of performance. Knowledge of how to integrate C++ and Python equips with a highly valuable skill set.

---

# Common libraries for C++ and Python integration (1/5)

Integrating C++ and Python code is a common need in software development, especially when you want to combine the high performance of C++ with the ease of use of Python. Several libraries are available for this purpose, each with its own set of advantages and drawbacks. Here are some of the most commonly used libraries:

1. **Boost.Python**
   - Pros:
     - Well-documented, widely used.
     - Seamless interoperability between C++ and Python.
     - Exposes C++ classes to Python and vice versa.
   - Cons:
     - Complex setup for beginners.
     - Larger binary size.
     - Slower compile times.

---

# Common libraries for C++ and Python integration (2/5)

2. **SWIG (Simplified Wrapper and Interface Generator)**
   - Pros:
     - Generates bindings for multiple languages.
     - Relatively easy for simple tasks.
     - Useful for multi-language projects.
   - Cons:
     - Less efficient, less "pythonic" interface code.
     - Difficult to debug.
     - Complex for advanced use cases.

---

# Common libraries for C++ and Python integration (3/5)

3. **pybind11**
   - Pros:
     - Modern, lightweight, easy to use.
     - Header-only library.
     - More pythonic bindings.
   - Cons:
     - Less advanced features than Boost.Python.
     - Less documentation, community support.
     - More manual work for complex bindings.

---

# Common libraries for C++ and Python integration (4/5)

4. **Cython**
   - Pros:
     - C extensions in Python-like syntax.
     - Significant performance improvements.
     - Good integration with Python ecosystem.
   - Cons:
     - Requires learning new syntax.
     - Not for exposing existing C++ codebases.
     - Variable performance gains.

---

# Common libraries for C++ and Python integration (5/5)

5. **ctypes**
   - Pros:
     - Part of Python standard library.
     - Simple for basic tasks.
     - Good for calling C functions from Python.
   - Cons:
     - Limited to C functions, not C++.
     - Manual type conversions.
     - Complex error handling.

---

# Why pybind11?

- Modern, relevant, and practical for industry demands.
- Header-only library, which simplifies the build process.
- Lightweight, and easy to use.
- Balances ease of use with powerful features.
- Generates more pythonic bindings compared to SWIG.
- Suitable for a range of projects, enhancing problem-solving skills.

:warning: pybind11 may require more manual work for complex bindings.

---

# PyPy and Numba overview

- **PyPy**
  - Alternative Python implementation focusing on speed.
  - JIT Compiler for runtime compilation.
  - Less memory usage, compatible with CPython.
  - Faster for long-running processes.
  - **Limitations**: Library support, JIT warm-up time.
- **Numba**
  - JIT compiler for Python and NumPy code.
  - Easy to use, significant performance improvements.
  - Integrates with Python scientific stack.
  - Supports CUDA GPU programming.
  - **Limitations**: Focused on numerical computing, learning curve for parallel programming, debugging challenges.

---

<!--
_class: titlepage
-->

# pybind11: installation

---

# pybind11 overview

pybind11 is a lightweight, header-only library that connects C++ types with Python. This tool is crucial for creating Python bindings of existing C++ code. Its design and functionality are similar to the Boost.Python library but with a focus on simplicity and minimalism. Pybind11 stands out for its ability to avoid the complexities associated with Boost, a comprehensive suite of utility libraries, by leveraging C++11 features.

[Documentation link](https://pybind11.readthedocs.io/en/stable/index.html)

---

# How to install (1/4)

There are multiple methods to acquire the pybind11 source, available on [GitHub](https://github.com/pybind/pybind11). The recommended approaches include via PyPI, through Conda, building from source, or importing it as a Git submodule.

## Include with PyPI

Pybind11 can be installed as a Python package from PyPI using Pip:

```bash
pip install pybind11
```

For direct availability in your environment root, use:

```bash
pip install "pybind11[global]"
```

This approach is advisable for virtual environments or within a `pyproject.toml` file, especially when using system Python, to avoid unwanted directory changes.

---

# How to install (2/4)

## Include with conda-forge

Conda users can obtain pybind11 via conda-forge:

```bash
conda install -c conda-forge pybind11
```

## Global install with brew

For macOS and Linux users, the brew package manager offers pybind11. Install it using:

```bash
brew install pybind11
```

---

# How to install (3/4)

## Build from source

If you prefer to build from source, use the following commands:

```bash
wget https://github.com/pybind/pybind11/archive/refs/tags/v2.11.1.tar.gz
tar xzvf v2.11.1.tar.gz

cd pybind11-2.11.1/
mkdir build && cd build

cmake .. -DCMAKE_INSTALL_PREFIX=/opt/pybind11
[sudo] make -j<N> install
```

---

# How to install (4/4)

## Include as a submodule

For Git-based projects, pybind11 can be incorporated as a submodule. In your Git repository, execute the following commands:

```bash
git submodule add -b stable ../../pybind/pybind11 extern/pybind11
git submodule update --init
```

This method assumes dependency placement in `extern/`. If not using GitHub, substitute with the complete https or ssh URL. Remember, some servers might require the `.git` extension.

After setup, include `extern/pybind11/include` in your project, or employ pybind11's integration tools.

---

# How to compile test cases on Linux/macOS

On Linux  you'll need to install the **python-dev** or **python3-dev** packages as well as **cmake**. On macOS, the included python version works out of the box, but **cmake** must still be installed.

After installing the prerequisites, run
```bash
mkdir build
cd build
cmake ..
make check -j4
```

---

# How to compile test cases on Windows

On Windows, only **Visual Studio 2017** (MSVC 14.1) and newer are supported, adding the [`/permissive`](https://docs.microsoft.com/en-us/cpp/build/reference/permissive-standards-conformance?view=vs-2017) compiler flag

To compile and run the tests:
```batch
mkdir build
cd build
cmake ..
cmake --build . --config Release --target check
```

This will create a Visual Studio project, compile and run the target, all from the command line.

---

# Note

If all tests fail, make sure that the Python binary and the testcases are compiled for the same processor type and bitness (i.e. either **i386** or **x86_64**). You can specify **x86_64** as the target architecture for the generated Visual Studio project using `cmake -A x64 ..`.

---

<!--
_class: titlepage
-->

# pybind11: basics

---

# Header and namespace conventions

For brevity, all code examples assume that the following two lines are present:

```cpp
#include <pybind11/pybind11.h>
namespace py = pybind11;
```

Some features may require additional headers, but those will be specified as needed.

---

# Creating bindings for a simple function

Let's start by creating Python bindings for an extremely simple function, which adds two numbers and returns their result. For simplicity, we'll put both this function and the binding code into a file named `example.cpp` with the following contents:

```cpp
#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
}
```

In practice, implementation and binding code will generally be located in separate files.

---

# The `PYBIND11_MODULE` macro

The `PYBIND11_MODULE` macro creates a function that will be called when an `import` statement is issued from within Python. The module name (`example`) is given as the first macro argument (it should not be in quotes). The second argument (`m`) defines a variable of type `py::module_ <module>` which is the main interface for creating bindings. The method `module_::def` generates binding code that exposes the `add()` function to Python.

---

# Note

Notice how little code was needed to expose our function to Python: all details regarding the function's parameters and return value were automatically inferred using template metaprogramming. This overall approach and the used syntax are borrowed from Boost.Python, though the underlying implementation is very different.

pybind11 is a header-only library, hence it is not necessary to link against any special libraries and there are no intermediate (magic) translation steps. On Linux, the above example can be compiled using the following command:

```bash
c++ -O3 -Wall -shared -std=c++11 -fPIC \
    $(python3 -m pybind11 --includes) \
    example.cpp -o example$(python3-config --extension-suffix)
```

---

# Note

The `python3 -m pybind11 --includes` command fetches the include paths for both pybind11 and Python headers. This assumes that pybind11 has been installed using `pip` or `conda`. If it hasn't, you can also manually specify `-I <path-to-pybind11>/include` together with the Python includes path `python3-config --includes`.

On macOS: the build command is almost the same but it also requires passing the `-undefined dynamic_lookup` flag so as to ignore missing symbols when building the module.

---

# Note

If you included pybind11 as a Git submodule, then use `$(python3-config --includes) -Iextern/pybind11/include` instead of `$(python3 -m pybind11 --includes)` in the above compilation.

The [Python example](https://github.com/pybind/python_example) and [CMake example](https://github.com/pybind/cmake_example) repositories are also a good place to start. They are both complete project examples with cross-platform build systems. The only difference between the two is that Python example uses Python's `setuptools` to build the module, whereas CMake example uses CMake (which may be preferable for existing C++ projects).

Building the above C++ code will produce a binary module file that can be imported to Python. Assuming that the compiled module is located in the current directory, the following interactive Python session shows how to load and execute the example:

```python
import example
example.add(1, 2) # Output: 3
```

---

# Keyword arguments

With a simple code modification, it is possible to inform Python about the names of the arguments ("i" and "j" in this case).

```cpp
m.def("add", &add, "A function which adds two numbers",
      py::arg("i"), py::arg("j"));
```

`arg` is one of several special tag classes which can be used to pass metadata into `module_::def`. With this modified binding code, we can now call the function using keyword arguments, which is a more readable alternative particularly for functions taking many parameters:

```python
import example
example.add(i=1, j=2) # Output: 3L
```

---

# Documentation

The keyword names also appear in the function signatures within the documentation.

```python
help(example)
```
>    ```
>    ...
>    FUNCTIONS
>        add(...)
>            Signature : (i: int, j: int) -> int
>
>            A function which adds two numbers
>    ```

---

A shorter notation for named arguments is also available:

```cpp
// Regular notation.
m.def("add1", &add, py::arg("i"), py::arg("j"));
// Shorthand.
using namespace pybind11::literals;
m.def("add2", &add, "i"_a, "j"_a);
```

The `_a` suffix forms a C++11 literal which is equivalent to `arg`.
Note that the literal operator must first be made visible with the directive
`using namespace pybind11::literals`. This does not bring in anything else
from the `pybind11` namespace except for literals.

---

# Default arguments

Suppose now that the function to be bound has default arguments, e.g.:

```cpp
int add(int i = 1, int j = 2) {
    return i + j;
}
```

Unfortunately, pybind11 cannot automatically extract these parameters, since they are not part of the function's type information. However, they are simple to specify using an extension of `arg`:
```cpp
m.def("add", &add, "A function which adds two numbers", py::arg("i") = 1, py::arg("j") = 2);

# Or, shorthand:
m.def("add2", &add, "i"_a=1, "j"_a=2);
```

The default values also appear within the documentation.

---

# Exporting variables

To expose a value from C++, use the `attr` function to register it in a module as shown below. Built-in types and general objects (more on that later) are automatically converted when assigned as attributes, and can be explicitly converted using the function `py::cast`.

```cpp
PYBIND11_MODULE(example, m) {
    m.attr("the_answer") = 42;
    py::object world = py::cast("World");
    m.attr("what") = world;
}
```

These are then accessible from Python:

```python
import example
example.the_answer # Output: 42
example.what # Output: 'World'
```

---

# Supported data types

A large number of data types are supported out of the box and can be used seamlessly as functions arguments, return values or with `py::cast` in general.

For a full overview, see the [official documentation](https://pybind11.readthedocs.io/en/stable/advanced/cast/index.html).

---

<!--
_class: titlepage
-->

# pybind11: binding object-oriented code

---

# Creating bindings for a custom type

Let's now look at a more complex example where we'll create bindings for a custom C++ data structure named `Pet`. Its definition is given below:

```cpp
struct Pet {
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

    std::string name;
};
```

The binding code for `Pet` looks as follows:

```cpp
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName);
}
```

`class_` creates bindings for a C++ *class* or *struct*-style data structure. `init` is a convenience function that takes the types of a constructor's parameters as template arguments and wraps the corresponding constructor (see the `custom_constructors` section for details). An interactive Python session demonstrating this example is shown below:

```python
import example
p = example.Pet("Molly")
print(p) # Output: <example.Pet object at 0x10cd98060>
p.getName() # Output: 'Molly'
p.setName("Charly")
p.getName() # Output: 'Charly'
```

**Note**: Static member functions can be bound in the same way using `class_::def_static`.

--

# Keyword and default arguments

It is possible to specify keyword and default arguments using the syntax discussed in the previous chapter. Refer to the sections `keyword_args` and `default_args` for details.

---

# Binding lambda functions

Note how `print(p)` produced a rather useless summary of our data structure in the example above:

```python
print(p) # Output: <example.Pet object at 0x10cd98060>
```

To address this, we could bind a utility function that returns a human-readable summary to the special method slot named `__repr__`. Unfortunately, there is no suitable functionality in the `Pet` data structure, and it would be nice if we did not have to change it.

---

This can easily be accomplished by binding a lambda function instead:

```cpp
py::class_<Pet>(m, "Pet")
    .def(py::init<const std::string &>())
    .def("setName", &Pet::setName)
    .def("getName", &Pet::getName)
    .def("__repr__",
         [](const Pet &a) {
             return "<example.Pet named '" + a.name + "'>";
         }
    );
```

With the above change, the same Python code now produces the following output:

```python
print(p) # Output: <example.Pet named 'Molly'>
```

---

# Instance and static fields

We can also directly expose the `name` field using the `class_::def_readwrite` method. A similar `class_::def_readonly` method also exists for `const` fields.

```cpp
py::class_<Pet>(m, "Pet")
    .def(py::init<const std::string &>())
    .def_readwrite("name", &Pet::name)
    // ...
```

This makes it possible to write

```python
p = example.Pet("Molly")
p.name # Output: 'Molly'
p.name = "Charly"
p.name # Output: 'Charly'
```

Now suppose that `Pet::name` was a private internal variable
that can only be accessed via setters and getters.

```cpp
class Pet {
public:
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }
private:
    std::string name;
};
```

In this case, the method `class_::def_property` (`class_::def_property_readonly` for read-only data) can be used to provide a field-like interface within Python that will transparently call the setter and getter functions:

```cpp
py::class_<Pet>(m, "Pet")
    .def(py::init<const std::string &>())
    .def_property("name", &Pet::getName, &Pet::setName)
    // ...
```

Write only properties can be defined by passing `nullptr` as the input for the read function.

.. seealso::

    Similar functions `class_::def_readwrite_static`,
    `class_::def_readonly_static` `class_::def_property_static`,
    and `class_::def_property_readonly_static` are provided for binding
    static variables and properties. Please also see the section on
    `static_properties` in the advanced part of the documentation.

# Dynamic attributes

Native Python classes can pick up new attributes dynamically:

```python
class Pet:
    name = "Molly"

p = Pet()
p.name = "Charly" # Overwrite existing.
p.age = 2 # Dynamically add a new attribute.
```

By default, classes exported from C++ do not support this and the only writable
attributes are the ones explicitly defined using `class_::def_readwrite`
or `class_::def_property`.

```cpp
py::class_<Pet>(m, "Pet")
    .def(py::init<>())
    .def_readwrite("name", &Pet::name);
```

Trying to set any other attribute results in an error:

```python
p = example.Pet()
p.name = "Charly" # Ok: attribute defined in C++.
p.age = 2
```
> AttributeError: 'Pet' object has no attribute 'age'

To enable dynamic attributes for C++ classes, the `py::dynamic_attr` tag
must be added to the `py::class_` constructor:

```cpp
py::class_<Pet>(m, "Pet", py::dynamic_attr())
    .def(py::init<>())
    .def_readwrite("name", &Pet::name);
```

Now everything works as expected:

```python
p = example.Pet()
p.name = "Charly" # Ok: overwrite value in C++.
p.age = 2 # Ok: dynamically add a new attribute.
p.__dict__  # Output: {'age': 2}
```

Note that there is a small runtime cost for a class with dynamic attributes.
Not only because of the addition of a `__dict__`, but also because of more
expensive garbage collection tracking which must be activated to resolve
possible circular references. Native Python classes incur this same cost by
default, so this is not anything to worry about. By default, pybind11 classes
are more efficient than native Python classes. Enabling dynamic attributes
just brings them on par.

---

# Inheritance and automatic downcasting

Suppose now that the example consists of two data structures with an
inheritance relationship:

```cpp
struct Pet {
    Pet(const std::string &name) : name(name) { }
    std::string name;
};

struct Dog : Pet {
    Dog(const std::string &name) : Pet(name) { }
    std::string bark() const { return "woof!"; }
};
```

There are two different ways of indicating a hierarchical relationship to
pybind11: the first specifies the C++ base class as an extra template
parameter of the `class_`:

```cpp
py::class_<Pet>(m, "Pet")
    .def(py::init<const std::string &>())
    .def_readwrite("name", &Pet::name);

// Method 1: template parameter:
py::class_<Dog, Pet /* <- specify C++ parent type */>(m, "Dog")
    .def(py::init<const std::string &>())
    .def("bark", &Dog::bark);
```

Alternatively, we can also assign a name to the previously bound `Pet`
`class_` object and reference it when binding the `Dog` class:

```cpp
py::class_<Pet> pet(m, "Pet");
pet.def(py::init<const std::string &>())
   .def_readwrite("name", &Pet::name);

// Method 2: pass parent class_ object:
py::class_<Dog>(m, "Dog", pet /* <- specify Python parent type */)
    .def(py::init<const std::string &>())
    .def("bark", &Dog::bark);
```

Functionality-wise, both approaches are equivalent. Afterwards, instances will expose fields and methods of both types:

```python
p = example.Dog("Molly")
p.name # Output: 'Molly'
p.bark() # Output: 'woof!'
```

The C++ classes defined above are regular non-polymorphic types with an inheritance relationship. This is reflected in Python:

```cpp
// Return a base pointer to a derived instance
m.def("pet_store", []() { return std::unique_ptr<Pet>(new Dog("Molly")); });
```

```python
p = example.pet_store()
type(p) # Output: Pet
# No pointer downcasting for regular non-polymorphic types.
p.bark()
```
> AttributeError: 'Pet' object has no attribute 'bark'

The function returned a `Dog` instance, but because it's a non-polymorphic type behind a base pointer, Python only sees a `Pet`. In C++, a type is only considered polymorphic if it has at least one virtual function and pybind11 will automatically recognize this:

```cpp
struct PolymorphicPet {
    virtual ~PolymorphicPet() = default;
};

struct PolymorphicDog : PolymorphicPet {
    std::string bark() const { return "woof!"; }
};

// Same binding code.
py::class_<PolymorphicPet>(m, "PolymorphicPet");
py::class_<PolymorphicDog, PolymorphicPet>(m, "PolymorphicDog")
    .def(py::init<>())
    .def("bark", &PolymorphicDog::bark);

// Again, return a base pointer to a derived instance.
m.def("pet_store2", []() { return std::unique_ptr<PolymorphicPet>(new PolymorphicDog); });
```

```python
p = example.pet_store2()
type(p) # Output: PolymorphicDog
p.bark() # Output: 'woof!'
```

Given a pointer to a polymorphic base, pybind11 performs automatic downcasting to the actual derived type. Note that this goes beyond the usual situation in C++: we don't just get access to the virtual functions of the base, we get the concrete derived type including functions and attributes that the base type may not even be aware of.

---

# Overloaded methods

Sometimes there are several overloaded C++ methods with the same name taking different kinds of input arguments:

```cpp
struct Pet {
    Pet(const std::string &name, int age) : name(name), age(age) { }

    void set(int age_) { age = age_; }
    void set(const std::string &name_) { name = name_; }

    std::string name;
    int age;
};
```

Attempting to bind `Pet::set` will cause an error since the compiler does not know which method the user intended to select. We can disambiguate by casting them to function pointers. Binding multiple functions to the same Python name automatically creates a chain of function overloads that will be tried in sequence.

```cpp
py::class_<Pet>(m, "Pet")
    .def(py::init<const std::string &, int>())
    .def("set", static_cast<void (Pet::*)(int)>(&Pet::set), "Set the pet's age")
    .def("set", static_cast<void (Pet::*)(const std::string &)>(&Pet::set), "Set the pet's name");
```

The overload signatures are also visible in the method's docstring.

If you have a C++14 compatible compiler, you can use an alternative syntax to cast the overloaded function:

```cpp
py::class_<Pet>(m, "Pet")
    .def("set", py::overload_cast<int>(&Pet::set), "Set the pet's age")
    .def("set", py::overload_cast<const std::string &>(&Pet::set), "Set the pet's name");
```

Here, `py::overload_cast` only requires the parameter types to be specified. The return type and class are deduced. This avoids the additional noise of `void (Pet::*)()` as seen in the raw cast. If a function is overloaded based on constness, the `py::const_` tag should be used:

```cpp
struct Widget {
    int foo(int x, float y);
    int foo(int x, float y) const;
};

py::class_<Widget>(m, "Widget")
    .def("foo_mutable", py::overload_cast<int, float>(&Widget::foo))
    .def("foo_const",   py::overload_cast<int, float>(&Widget::foo, py::const_));
```

If you prefer the `py::overload_cast` syntax but have a C++11 compatible compiler only, you can use `py::detail::overload_cast_impl` with an additional set of parentheses:

```cpp
template <typename... Args>
using overload_cast_ = pybind11::detail::overload_cast_impl<Args...>;

py::class_<Pet>(m, "Pet")
    .def("set", overload_cast_<int>()(&Pet::set), "Set the pet's age")
    .def("set", overload_cast_<const std::string &>()(&Pet::set), "Set the pet's name");
```

.. note::

    To define multiple overloaded constructors, simply declare one after the
    other using the `.def(py::init<...>())` syntax. The existing machinery
    for specifying keyword and default arguments also works.

---

# Enumerations and internal types

Let's now suppose that the example class contains internal types like enumerations, e.g.:

```cpp
struct Pet {
    enum Kind {
        Dog = 0,
        Cat
    };

    struct Attributes {
        float age = 0;
    };

    Pet(const std::string &name, Kind type) : name(name), type(type) { }

    std::string name;
    Kind type;
    Attributes attr;
};
```

The binding code for this example looks as follows:

```cpp
py::class_<Pet> pet(m, "Pet");

pet.def(py::init<const std::string &, Pet::Kind>())
    .def_readwrite("name", &Pet::name)
    .def_readwrite("type", &Pet::type)
    .def_readwrite("attr", &Pet::attr);

py::enum_<Pet::Kind>(pet, "Kind")
    .value("Dog", Pet::Kind::Dog)
    .value("Cat", Pet::Kind::Cat)
    .export_values();

py::class_<Pet::Attributes>(pet, "Attributes")
    .def(py::init<>())
    .def_readwrite("age", &Pet::Attributes::age);
```

---

To ensure that the nested types `Kind` and `Attributes` are created within the scope of `Pet`, the `pet` `class_` instance must be supplied to the `enum_` and `class_` constructor. The `enum_::export_values` function exports the enum entries into the parent scope, which should be skipped for newer C++11-style strongly typed enums.

```python
p = Pet("Lucy", Pet.Cat)
p.type # Output: Kind.Cat
int(p.type) # Output: 1L
```

The entries defined by the enumeration type are exposed in the `__members__` property:

```python
Pet.Kind.__members__ # Output: {'Dog': Kind.Dog, 'Cat': Kind.Cat}
```

The `name` property returns the name of the enum value as a unicode string.

.. note::

    It is also possible to use `str(enum)`, however these accomplish different goals. The following shows how these two approaches differ.

    ```python
    p = Pet("Lucy", Pet.Cat)
    pet_type = p.type
    pet_type # Output: Pet.Cat
    str(pet_type) # Output: 'Pet.Cat'
    pet_type.name # Output: 'Cat'
    ```

.. note::

    When the special tag `py::arithmetic()` is specified to the `enum_` constructor, pybind11 creates an enumeration that also supports rudimentary arithmetic and bit-level operations like comparisons, and, or, xor, negation, etc.

    ```cpp
    py::enum_<Pet::Kind>(pet, "Kind", py::arithmetic())
    ...
    ```
    
    By default, these are omitted to conserve space.

.. warning::

    Contrary to Python customs, enum values from the wrappers should not be compared using `is`, but with `==` (see `#1177 <https://github.com/pybind/pybind11/issues/1177>`_ for background).

---

<!--
_class: titlepage
-->

# pybind11: building

---

# How to compile

To compile C++ code with Pybind11, use the following command:
```bash
g++ -std=gnu++11 -O3 -shared -fPIC \
    -isystem /path/to/pybind11/include $(python3-config --cflags --ldflags --libs) \
    example.cpp -o example.so
```

Alternatively, you can use CMake with the provided `CMakeLists.txt`.

---

# How to compile using CMake

To compile and run your Pybind11 code with CMake, follow these steps:
```bash
cd /path/to/example/
mkdir build && cd build
cmake -Dpybind11_DIR=${mkPybind11Prefix} ..
make
```
For running the compiled module, adjust your `PYTHONPATH` accordingly.

---

# How to compile using `setup.py`

`setup.py` is a Python script commonly used in Python projects for tasks like building, distributing, and installing module packages. In Pybind11, it compiles and links C++ code into Python modules.

Below is a basic `setup.py` file structure for Pybind11:

```python
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools

class get_pybind_include(object):
    # Helper class to determine the pybind11 include path
    def __str__(self):
        import pybind11
        return pybind11.get_include()

ext_modules = [
    Extension(
        'your_module_name',  # Name of the module
        ['your_module.cpp'],  # C++ source files
        include_dirs=[
            get_pybind_include(),  # Path to pybind11 includes
            '/path/to/other/includes',  # Additional include paths
        ],
        language='c++'
    ),
]

setup(
    name='your_module_name',
    version='0.1',
    author='Your Name',
    author_email='your.email@example.com',
    description='A Python module using Pybind11',
    long_description='',
    ext_modules=ext_modules,
    install_requires=['pybind11>=2.5.0'],  # pybind11 requirement
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
)
```

---

# Steps to use `setup.py`

1. **Create the `setup.py` file**: Place it in your project's root directory.

2. **Modify the file**: Change 'your_module_name' and 'your_module.cpp' to your module's name and C++ source file name. Adjust paths as needed.

3. **Build the module**:
   ```bash
   python setup.py build_ext --inplace
   ```
   This compiles the C++ code into a shared object file (.so).

4. **Install the module**:
   ```bash
   python setup.py install
   ```

---

# Notes

- Ensure Pybind11 and necessary libraries are installed.
- `get_pybind_include` locates the Pybind11 headers.
- Add complex compilation options or multiple C++ source files as needed.

---

# Building with setuptools

For projects on PyPI, building with setuptools is the way to go. Sylvain Corlay has kindly provided an example project which shows how to set up everything, including automatic generation of documentation using Sphinx. Please refer to the [python example](https://github.com/pybind/python_example) repository.

A helper file is provided with pybind11 that can simplify usage with setuptools.

To use pybind11 inside your `setup.py`, you have to have some system to ensure that `pybind11` is installed when you build your package. There are four possible ways to do this, and pybind11 supports all four: You can ask all users to install pybind11 beforehand (bad), you can use `setup_helpers-pep518` (good, but very new and requires Pip 10), `setup_helpers-setup_requires` (discouraged by Python packagers now that PEP 518 is available, but it still works everywhere), or you can `setup_helpers-copy-manually` (always works but you have to manually sync your copy to get updates).

An example of a `setup.py` using pybind11's helpers:

```python
from glob import glob
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension

ext_modules = [
    Pybind11Extension(
        "python_example",
        sorted(glob("src/*.cpp")),  # Sort source files for reproducibility
    ),
]

setup(..., ext_modules=ext_modules)
```

If you want to do an automatic search for the highest supported C++ standard, that is supported via a `build_ext` command override; it will only affect `Pybind11Extensions`:

```python
from glob import glob
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "python_example",
        sorted(glob("src/*.cpp")),
    ),
]

setup(..., cmdclass={"build_ext": build_ext}, ext_modules=ext_modules)
```

If you have single-file extension modules that are directly stored in the Python source tree (`foo.cpp` in the same directory as where a `foo.py` would be located), you can also generate `Pybind11Extensions` using `setup_helpers.intree_extensions`: ``intree_extensions(["path/to/foo.cpp", ...])` returns a list of `Pybind11Extensions`` which can be passed to `ext_modules`, possibly after further customizing their attributes (`libraries`, `include_dirs`, etc.).  By doing so, a `foo.*.so` extension module will be generated and made available upon installation.

`intree_extension` will automatically detect if you are using a `src`-style layout (as long as no namespace packages are involved), but you can also explicitly pass `package_dir` to it (as in `setuptools.setup`).

Since pybind11 does not require NumPy when building, a light-weight replacement for NumPy's parallel compilation distutils tool is included. Use it like this:

```python
from pybind11.setup_helpers import ParallelCompile

# Optional multithreaded build.
ParallelCompile("NPY_NUM_BUILD_JOBS").install()

setup(...)
```

The argument is the name of an environment variable to control the number of threads, such as `NPY_NUM_BUILD_JOBS` (as used by NumPy), though you can set something different if you want; `CMAKE_BUILD_PARALLEL_LEVEL` is another choice a user might expect. You can also pass `default=N` to set the default number of threads (0 will take the number of threads available) and `max=N`, the maximum number of threads; if you have a large extension you may want set this to a memory dependent number.

If you are developing rapidly and have a lot of C++ files, you may want to avoid rebuilding files that have not changed. For simple cases were you are using `pip install -e .` and do not have local headers, you can skip the rebuild if an object file is newer than its source (headers are not checked!) with the following:

```python
from pybind11.setup_helpers import ParallelCompile, naive_recompile
ParallelCompile("NPY_NUM_BUILD_JOBS", needs_recompile=naive_recompile).install()
```


If you have a more complex build, you can implement a smarter function and pass it to `needs_recompile`, or you can use [Ccache]_ instead. ``CXX="cache g++" pip install -e .`` would be the way to use it with GCC, for example. Unlike the simple solution, this even works even when not compiling in editable mode, but it does require Ccache to be installed.

Keep in mind that Pip will not even attempt to rebuild if it thinks it has already built a copy of your code, which it deduces from the version number. One way to avoid this is to use [setuptools_scm]_, which will generate a version number that includes the number of commits since your last tag and a hash for a dirty directory. Another way to force a rebuild is purge your cache or use Pip's `--no-cache-dir` option.

1. PEP 518 requirements (Pip 10+ required)

If you use `PEP 518's <https://www.python.org/dev/peps/pep-0518/>`_
`pyproject.toml` file, you can ensure that `pybind11` is available during
the compilation of your project.  When this file exists, Pip will make a new
virtual environment, download just the packages listed here in `requires=`,
and build a wheel (binary Python package). It will then throw away the
environment, and install your wheel.

Your `pyproject.toml` file will likely look something like this:

```toml
    [build-system]
    requires = ["setuptools>=42", "pybind11>=2.6.1"]
    build-backend = "setuptools.build_meta"
```

.. note::

    The main drawback to this method is that a `PEP 517`_ compliant build tool,
    such as Pip 10+, is required for this approach to work; older versions of
    Pip completely ignore this file. If you distribute binaries (called wheels
    in Python) using something like `cibuildwheel`_, remember that `setup.py`
    and `pyproject.toml` are not even contained in the wheel, so this high
    Pip requirement is only for source builds, and will not affect users of
    your binary wheels. If you are building SDists and wheels, then
    `pypa-build`_ is the recommended official tool.

1. Classic `setup_requires`

If you want to support old versions of Pip with the classic
`setup_requires=["pybind11"]` keyword argument to setup, which triggers a
two-phase `setup.py` run, then you will need to use something like this to
ensure the first pass works (which has not yet installed the `setup_requires`
packages, since it can't install something it does not know about):

```python
    try:
        from pybind11.setup_helpers import Pybind11Extension
    except ImportError:
        from setuptools import Extension as Pybind11Extension
```

It doesn't matter that the Extension class is not the enhanced subclass for the
first pass run; and the second pass will have the `setup_requires`
requirements.

This is obviously more of a hack than the PEP 518 method, but it supports
ancient versions of Pip.

---

1. Copy manually

You can also copy `setup_helpers.py` directly to your project; it was
designed to be usable standalone, like the old example `setup.py`. You can
set `include_pybind11=False` to skip including the pybind11 package headers,
so you can use it with git submodules and a specific git version. If you use
this, you will need to import from a local file in `setup.py` and ensure the
helper file is part of your MANIFEST.


Closely related, if you include pybind11 as a subproject, you can run the
`setup_helpers.py` inplace. If loaded correctly, this should even pick up
the correct include for pybind11, though you can turn it off as shown above if
you want to input it manually.

Suggested usage if you have pybind11 as a submodule in `extern/pybind11`:

```python
DIR = os.path.abspath(os.path.dirname(__file__))

sys.path.append(os.path.join(DIR, "extern", "pybind11"))
from pybind11.setup_helpers import Pybind11Extension  # noqa: E402

del sys.path[-1]
```

---

# Building with CMake

For C++ codebases that have an existing CMake-based build system, a Python
extension module can be created with just a few lines of code:

```cmake
cmake_minimum_required(VERSION 3.5...3.27)
project(example LANGUAGES CXX)

add_subdirectory(pybind11)
pybind11_add_module(example example.cpp)
```

This assumes that the pybind11 repository is located in a subdirectory named
`pybind11` and that the code is located in a file named `example.cpp`.
The CMake command `add_subdirectory` will import the pybind11 project which
provides the `pybind11_add_module` function. It will take care of all the
details needed to build a Python extension module on any platform.

A working sample project, including a way to invoke CMake from `setup.py` for
PyPI integration, can be found in the [CMake example](https://github.com/pybind/cmake_example) repository.

1. pybind11_add_module

To ease the creation of Python extension modules, pybind11 provides a CMake
function with the following signature:

```cmake
pybind11_add_module(<name> [MODULE | SHARED] [EXCLUDE_FROM_ALL]
                    [NO_EXTRAS] [THIN_LTO] [OPT_SIZE] source1 [source2 ...])
```

This function behaves very much like CMake's builtin `add_library` (in fact,
it's a wrapper function around that command). It will add a library target
called `<name>` to be built from the listed source files. In addition, it
will take care of all the Python-specific compiler and linker flags as well
as the OS- and Python-version-specific file extension. The produced target
`<name>` can be further manipulated with regular CMake commands.

`MODULE` or `SHARED` may be given to specify the type of library. If no
type is given, `MODULE` is used by default which ensures the creation of a
Python-exclusive module. Specifying `SHARED` will create a more traditional
dynamic library which can also be linked from elsewhere. `EXCLUDE_FROM_ALL`
removes this target from the default build (see CMake docs for details).

Since pybind11 is a template library, `pybind11_add_module` adds compiler
flags to ensure high quality code generation without bloat arising from long
symbol names and duplication of code in different translation units. It
sets default visibility to *hidden*, which is required for some pybind11
features and functionality when attempting to load multiple pybind11 modules
compiled under different pybind11 versions.  It also adds additional flags
enabling LTO (Link Time Optimization) and strip unneeded symbols. See the
`FAQ entry <faq:symhidden>` for a more detailed explanation. These
latter optimizations are never applied in `Debug` mode.  If `NO_EXTRAS` is
given, they will always be disabled, even in `Release` mode. However, this
will result in code bloat and is generally not recommended.

As stated above, LTO is enabled by default. Some newer compilers also support
different flavors of LTO such as `ThinLTO`_. Setting `THIN_LTO` will cause
the function to prefer this flavor if available. The function falls back to
regular LTO if `-flto=thin` is not available. If
`CMAKE_INTERPROCEDURAL_OPTIMIZATION` is set (either `ON` or `OFF`), then
that will be respected instead of the built-in flag search.

.. note::

   If you want to set the property form on targets or the
   `CMAKE_INTERPROCEDURAL_OPTIMIZATION_<CONFIG>` versions of this, you should
   still use `set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)` (otherwise a
   no-op) to disable pybind11's ipo flags.

The `OPT_SIZE` flag enables size-based optimization equivalent to the
standard `/Os` or `-Os` compiler flags and the `MinSizeRel` build type,
which avoid optimizations that that can substantially increase the size of the
resulting binary. This flag is particularly useful in projects that are split
into performance-critical parts and associated bindings. In this case, we can
compile the project in release mode (and hence, optimize performance globally),
and specify `OPT_SIZE` for the binding target, where size might be the main
concern as performance is often less critical here. A ~25% size reduction has
been observed in practice. This flag only changes the optimization behavior at
a per-target level and takes precedence over the global CMake build type
(`Release`, `RelWithDebInfo`) except for `Debug` builds, where
optimizations remain disabled.

1. Configuration variables

By default, pybind11 will compile modules with the compiler default or the
minimum standard required by pybind11, whichever is higher.  You can set the
standard explicitly with
`CMAKE_CXX_STANDARD <https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html>`_:

```cmake
set(CMAKE_CXX_STANDARD 14 CACHE STRING "C++ version selection")  # or 11, 14, 17, 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # optional, ensure standard is supported
set(CMAKE_CXX_EXTENSIONS OFF)  # optional, keep compiler extensions off
```

The variables can also be set when calling CMake from the command line using
the `-D<variable>=<value>` flag. You can also manually set `CXX_STANDARD`
on a target or use `target_compile_features` on your targets - anything that
CMake supports.

Classic Python support: The target Python version can be selected by setting
`PYBIND11_PYTHON_VERSION` or an exact Python installation can be specified
with `PYTHON_EXECUTABLE`.  For example:

```bash
cmake -DPYBIND11_PYTHON_VERSION=3.6 ...

# Another method:
cmake -DPYTHON_EXECUTABLE=/path/to/python ...

# This often is a good way to get the current Python, works in environments:
cmake -DPYTHON_EXECUTABLE=$(python3 -c "import sys; print(sys.executable)") ..
```

1. find_package vs. add_subdirectory

For CMake-based projects that don't include the pybind11 repository internally,
an external installation can be detected through `find_package(pybind11)`.
See the `Config file`_ docstring for details of relevant CMake variables.

```cmake
cmake_minimum_required(VERSION 3.4...3.18)
project(example LANGUAGES CXX)

find_package(pybind11 REQUIRED)
pybind11_add_module(example example.cpp)
```

Note that `find_package(pybind11)` will only work correctly if pybind11
has been correctly installed on the system, e. g. after downloading or cloning
the pybind11 repository  :

```bash
cd pybind11
mkdir build
cd build
cmake ..
make -j<N> install
```

Once detected, the aforementioned `pybind11_add_module` can be employed as
before. The function usage and configuration variables are identical no matter
if pybind11 is added as a subdirectory or found as an installed package. You
can refer to the same [CMake example](https://github.com/pybind/cmake_example) repository for a full sample project
-- just swap out `add_subdirectory` for `find_package`.

<!--
_class: titlepage
-->

# Examples

---

# Benchmark

The example provided in the `c++_vs_py` folder showcases a performance comparison test between bound C++ code and native Python code on a simple linear algebra operation, such as a matrix-matrix product.

The code can be compiled with:
```bash
g++ -O3 -Wall -shared -std=c++11 -fPIC \
    $(python3 -m pybind11 --includes) \
    matrix_multiplication.cpp -o matrix_ops$(python3-config --extension-suffix)
```

**Expected results**
Typically, the C++ implementation should be significantly faster than the pure Python implementation for several reasons:
- **Execution speed**: C++ is a compiled language and is generally faster than Python, an interpreted language, especially for computation-intensive tasks.
- **Optimization**: Compilers for C++ can optimize the code for performance, whereas Python's flexibility and dynamic typing can introduce overhead.
- **Handling of loops**: C++ is more efficient in handling loops and arithmetic operations compared to Python.

---

# Notes

- The actual performance gain can vary depending on the system, the size of the matrices, and the compiler optimizations.
- For matrix operations, libraries like NumPy in Python are highly optimized and can offer performance close to C++, but in this comparison, we are using a pure Python implementation to illustrate the difference more clearly.
- Remember that developing and maintaining C++ code requires more effort compared to Python, so the decision to use C++ should consider both performance benefits and development costs.

---

# Other examples

The examples provided in the `examples` folder are adapted and extended versions from [this GitHub repository](https://github.com/tdegeus/pybind11_examples). They demonstrate the use of Pybind11 in various scenarios.

# Further readings

- [pybind11 documentation](https://pybind11.readthedocs.io/en/stable/)
- [Using pybind11](https://people.duke.edu/~ccc14/sta-663-2016/18G_C++_Python_pybind11.html)

---

<!--
_class: titlepage
-->

# :tada: That's all Folks!
