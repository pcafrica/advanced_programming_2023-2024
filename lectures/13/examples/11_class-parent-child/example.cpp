#include <pybind11/pybind11.h>

#include <iostream>
#include <string>

// ------------------
// Regular C++ header
// ------------------

// Parent class.
class Animal {
public:
  virtual std::string talk(int n_times) const = 0;
};

// Derived class.
class Dog : public Animal {
public:
  virtual std::string talk(int n_times) const override;
};

// Derived class.
class Cat : public Animal {
public:
  virtual std::string talk(int n_times) const override;
};

// Function that takes the parent polymorphically.
std::string talk(const Animal &animal, int n_times = 1);

// ----------------
// Regular C++ code
// ----------------

inline std::string Dog::talk(int n_times) const {
  std::string result;

  for (int i = 0; i < n_times; ++i)
    result += "woof! ";

  return result;
}

inline std::string Cat::talk(int n_times) const {
  std::string result;

  for (int i = 0; i < n_times; ++i)
    result += "meow! ";

  return result;
}

std::string talk(const Animal &animal, int n_times) {
  return animal.talk(n_times);
}

// -----------------------------
// Python interface - trampoline
// -----------------------------

class PyAnimal : public Animal {
public:
  // Inherit the constructors.
  using Animal::Animal;

  // Trampoline (one for each virtual function).
  virtual std::string talk(int n_times) const override {
    PYBIND11_OVERRIDE_PURE(
        std::string, /* Return type. */
        Animal,      /* Parent class. */
        talk,        /* Name of function in C++ (must match Python name). */
        n_times      /* Argument(s). */
    );
  }
};

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
  py::class_<Animal, PyAnimal>(m, "Animal")
      .def(py::init<>())
      .def("talk", &Animal::talk);

  py::class_<Dog, Animal>(m, "Dog").def(py::init<>());

  py::class_<Cat, Animal>(m, "Cat").def(py::init<>());

  m.def("talk", &talk, py::arg("animal"), py::arg("n_times") = 1);
}
