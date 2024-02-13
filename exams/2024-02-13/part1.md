# Part 1: Open-ended questions

## Question 1
Describe a specific task you automated using a shell script.<br>
What was the task, and how did your script improve the process? Share the script and explain its functionality.

## Answer


---

## Question 2
Design a minimal C++ class hierarchy for a simple game engine that includes entities like `Player`, `Enemy`, and `Item`.<br>
Discuss how polymorphism, inheritance, or other forms of relationship between classes can be used to organize and extend the engine.

## Answer


---

## Question 3
Provide an example of how you've used a functor or lambda function in C++ to simplify your code, especially in the context of STL algorithms.<br>
Explain your choice and its benefits.

## Answer


---

## Question 4
Consider the following C++ code snippet.<br>
Detect as many errors as you can and fix them.

```cpp
class Shape {
public:
    virtual void print() const = 0;
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}
    
    virtual void print() const override {
        std::cout << "A circle with radius " << radius << "." << std::endl;
    }

private:
    double radius;
};

auto s1 = &Shape();
s1->print();

auto s2 = new Circle(0.5);
s2->print();

delete s1;
delete s2;
```

## Answer


---

## Question 5
The following C++ code snippet implements the Babylonian method to approximate the square root of a given number at compile time, exploiting template metaprogramming.<br>
However, the method only works for integer square roots. How would you use it to approximate, e.g., $\sqrt{2}$ at compile time?

```cpp
#include <iostream>
#include <type_traits>

template <unsigned int N, unsigned int X, unsigned int NextX = (X + N / X) / 2>
struct BabylonianMethod : BabylonianMethod<N, NextX> {};

// Specialization to stop recursion.
template <unsigned int N, unsigned int X>
struct BabylonianMethod<N, X, X> {
    static constexpr unsigned int value = X;
};

// Helper template to initiate the Babylonian method with a good enough first guess.
template <unsigned int N>
using Sqrt = BabylonianMethod<N, N / 2 + 1>;

int main() {
    // Compute square root of 16 at compile time.
    constexpr unsigned int sqrt16 = Sqrt<16>::value;
    std::cout << "Square root of 16 is " << sqrt16 << std::endl;

    return 0;
}
```

## Answer


---

## Question 6
Explain how you would convert an existing `Makefile` project to use CMake, highlighting the steps involved in creating a `CMakeLists.txt` file.<br>
Discuss benefits and disadvantages, if any, of this transition.

## Answer


---

## Question 7
Share your experience with debugging or profiling a performance issue in a C++ or Python application.<br>
Which tools or techniques did you use, and how did you resolve the issue?

## Answer


---

## Question 8
Explain the difference between list comprehensions and generator expressions in Python.<br>
Give an example of a scenario where using a generator would be significantly more memory-efficient than a list comprehension.

## Answer


---

## Question 9

Given the following Python code, which uses a custom class decorator to modify or add methods to classes, analyze how the decorator affects both the `BaseClass` and the `ChildClass` with respect to the methods `greet` and `farewell`.<br>
Considered the intricacies of inheritance, method overriding, and dynamic attribute modification introduced by the decorator, explain what happens when instances of these classes call the `greet` and `farewell` methods.

```python
def class_decorator(method_name):
    def wrapper(cls):
        original_method = getattr(cls, method_name, None)
        if original_method:
            def new_method(self, *args, **kwargs):
                return f"Modified behavior: {original_method(self, *args, **kwargs)}"
            setattr(cls, method_name, new_method)
        else:
            def new_method(self):
                return f"New method added to {cls.__name__}"
            setattr(cls, method_name, new_method)
        return cls
    return wrapper

@class_decorator("greet")
class BaseClass:
    def greet(self):
        return "Hello from BaseClass"

@class_decorator("greet")
@class_decorator("farewell")
class ChildClass(BaseClass):
    def farewell(self):
        return "Goodbye from ChildClass"
```

## Answer


---

## Question 10
Is it possible to use pybind11 to execute Python code from within C++ code?<br>
What are possible use cases in the field of data science and scientific computing?

## Answer

