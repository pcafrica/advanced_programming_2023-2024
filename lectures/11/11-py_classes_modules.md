<!--
title: Lecture 11
paginate: true

_class: titlepage
-->

# Lecture 11
<br>

## Object-oriented programming. Classes, inheritance and polymorphism. Modules and packages.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 05 Dec 2023

---

# Outline

1. OOP in Python
2. Decorators
3. Inheritance and polymorphism
4. Modules and packages

---

<!--
_class: titlepage
-->

# Object-oriented programming in Python

---

# Object-oriented programming in Python

In Python, classes are a powerful tool for creating custom data types, allowing us to bundle data and functionality together. Instances of a class, known as objects, offer a structured and efficient way to manage and manipulate data. Let's delve deeper into classes, exploring their benefits and practical applications.

---

# Understanding classes and objects

We've encountered built-in data types like `dict` and `list`. However, Python allows us to define our own data types using classes. A class serves as a blueprint for creating objects, following the principles of [object-oriented programming](https://en.wikipedia.org/wiki/Object-oriented_programming).

```python
d = dict()
```

In this example, `d` is an object, while `dict` is a type.

```python
type(d)
```
> dict

```python
type(dict)
```
> type

We refer to `d` as an **instance** of the **type** `dict`.

---

# The need for custom classes

Custom classes become invaluable when we need to organize and manage complex data structures efficiently. Let's illustrate this with an example involving the Advanced Programming course (AdvProg) members. Initially, we store information in a dictionary:
```python
advprog_1 = {'first': Pasquale Claudio', 'last': 'Africa', 'email': 'pafrica@sissa.it'}
```

To extract a member's full name, we define a function:
```python
def full_name(first, last):
    return f"{first} {last}"
```

This approach requires repetitive code for each member:
```python
advprog_2 = {'first': 'Marco', 'last': 'Feder', 'email': mfeder@sissa.it'}
full_name(advprog_2['first'], advprog_2['last'])
```

---

# Creating a class for efficiency

To address the inefficiency, we can create a class as a blueprint for AdvProg members:

```python
class AdvProgMember:
    pass
```

We enhance this blueprint by adding an `__init__` method to initialize instances with specific data:

```python
class AdvProgMember:
    def __init__(self, first, last, email):
        self.first = first
        self.last = last
        self.email = f"{email.lower()}"
```

---

# The `self`

Class methods have only one specific difference from ordinary functions - they must have an extra first name that has to be added to the beginning of the parameter list, but you **do not** give a value for this parameter when you call the method, Python will provide it. This particular variable refers to the object *itself*, and by convention, it is given the name `self`.

You must be wondering how Python gives the value for `self` and why you don't need to give a value for it. An example will make this clear. Say you have a class called `MyClass` and an instance of this class called `myobject`. When you call a method of this object as `myobject.method(arg1, arg2)`, this is automatically converted by Python into `MyClass.method(myobject, arg1, arg2)` - this is all the special `self` is about.

This also means that if you have a method which takes no arguments, then you still have to have one argument - the `self`.

---

# The `__init__` method

There are many method names which have special significance in Python classes. We will see the significance of the `__init__` method now.

The `__init__` method is run as soon as an object of a class is instantiated (i.e. created). The method is useful to do any *initialization* (i.e. passing initial values to your object) you want to do with your object. Notice the double underscores both at the beginning and at the end of the name.

We do not explicitly call the `__init__` method, but it is automatically invoked when creating an instance of a class:

```python
advprog_1 = AdvProgMember('Pasquale Claudio', 'Africa', 'pafrica@sissa.it)
print(advprog_1.first)
print(advprog_1.last)
print(advprog_1.email)
```

---

# Methods

To simplify accessing a member's full name, we integrate it as a class method:

```python
class AdvProgMember:
    def __init__(self, first, last, email):
        self.first = first
        self.last = last
        self.email = f"{email.lower()}"

    def full_name(self): # Notice 'self' as an input argument.
        return f"{self.first} {self.last}"
```

Using the method:

```python
advprog_1 = AdvProgMember('Pasquale Claudio', 'Africa')
print(advprog_1.full_name())
```

---

# Class vs. object (or instance) attributes

Attributes can be instance-specific (`advprog_1.first`) or shared among all instances (`AdvProgMember.campus`). Class attributes are defined outside the `__init__` method.

```python
class AdvProgMember:
    campus = "SISSA"

    def __init__(self, first, last, email):
        self.first = first
        self.last = last
        self.email = f"{email.lower()}"
```

Accessing class attributes:

```python
advprog_1 = AdvProgMember('Pasquale Claudio', 'Africa')
print(f"{advprog_1.first} is at campus {advprog_1.campus}.")
print(f"{advprog_1.first} is at campus {AdvProgMember.campus}.")
```

## :warning: Changing class attributes affects all instances:

---

# Class methods

Besides regular methods, classes offer class methods and static methods. Class methods, identified by `@classmethod`, act on the class itself, often serving as alternative constructors.

```python
class AdvProgMember:
    @classmethod
    def from_csv(cls, csv_name):
        first, last = csv_name.split(',')
        return cls(first, last)
```

Using the class method:

```python
advprog_1 = AdvProgMember.from_csv('Pasquale Claudio,Africa,pafrica@sissa.it')
advprog_1.full_name()
```

---

# Static methods

Static methods, marked with `@staticmethod`, operate independently of instances and classes but are relevant to the class.

```python
class AdvProgMember:
    @staticmethod
    def is_exam_date(date):
        return True if date in ["Jan 17th", "Feb 13th"] else False
```

Using the static method:

```python
print(f"Is Dec 5th an exam date? {AdvProgMember.is_exam_date("Dec 5th")}")
print(f"Is Feb 13th an exam date? {AdvProgMember.is_exam_date("Feb 13th")}")
```

---

# Notes for C++ programmers

- In Python, even integers are treated as objects (of the `int` class). This is unlike C++ where integers are primitive native type.

- The `self` in Python is equivalent to the `this` pointer in C++.

- All class members (including the data members) are *public* and all the methods are *virtual* in Python. **One exception**: If you use data members with names using the _double underscore prefix_ such as `__myvar`, Python uses name-mangling to effectively make it a private variable.


---

<!--
_class: titlepage
-->

# Decorators

---

# Understanding and creating Python decorators

Decorators in Python offer a powerful way to enhance the functionality of functions or methods. They act as wrappers, allowing you to extend or modify the behavior of the original function. Let's delve deeper into decorators with examples and explore their practical applications.

Decorators can be imagined to be a shortcut to calling a wrapper function (i.e. a function that "wraps" around another function so that it can do something before or after the inner function), so applying the `@classmethod` decorator is the same as calling:

```python
from_csv = classmethod(from_csv)
```

---

# Basics of decorators

Decorators are essentially functions that take another function as input, enhance its capabilities, and return a modified version of the original function. To illustrate, consider the following decorator:

```python
def my_decorator(original_func):
    def wrapper():
        print(f"A decoration before {original_func.__name__}.")
        result = original_func()
        print(f"A decoration after {original_func.__name__}.")
        return result
    return wrapper
```

As a function was returned to us, we can execute it by adding parentheses:

```python
my_decorator(original_func)()

# Or:
original_func = my_decorator(original_func)
original_func()
```

---

# Improved syntax using `@`

While the previous example works, Python provides a more readable syntax using the `@` symbol. The equivalent of the previous example using this syntax is:
This decorator, when applied to a function, surrounds the function call with additional actions. For instance:

```python
@my_decorator
def original_func():
    print("I'm the original function!")

original_func()
```

Output:

```
A decoration before original_func.
I'm the original function!
A decoration after original_func.
```

---

# Practical example: timer decorator (1/2)

Now, let's create a more practical decorator that measures the execution time of a function. This example utilizes the `time` module:

```python
import time

def timer(my_function):
    def wrapper():
        t1 = time.time()
        result = my_function()
        t2 = time.time()
        print(f"{my_function.__name__} ran in {t2 - t1:.3f} sec")
        return result
    return wrapper
```

---

# Practical example: timer decorator (2/2)

Applying this decorator to a function allows us to measure its execution time:

```python
@timer
def silly_function():
    for i in range(1e7):
        if (i % 1e6) == 0:
            print(i)

silly_function()
```

Output:

```
0
1000000
2000000
...
9000000
silly_function ran in 0.601 sec
```

---

# Built-in decorators

Python comes with built-in decorators like `classmethod` and `staticmethod`, which are implemented in C for efficiency. Although we won't dive into their implementation, they are widely used in practice.

In conclusion, decorators provide a flexible and elegant way to enhance the behavior of functions in Python. While creating custom decorators may not be a daily necessity, understanding them is crucial for leveraging Python's full potential. Explore built-in decorators and consider creating your own when specific functionality is needed.

---

<!--
_class: titlepage
-->

# Inheritance and polymorphism

### Inheritance & Subclasses

Inheritance in Python enables classes to inherit methods and attributes from other classes. Previously, we worked with the `advprog_member` class, but now let's delve into creating more specialized classes like `advprog_student` and `advprog_instructor`.

```python
class advprog_member:
    # ... (unchanged)
```

Now, to create an `advprog_student` class inheriting from `advprog_member`:

```python
class advprog_student(advprog_member):
    pass
```

Creating instances of `advprog_student` and accessing inherited methods:

```python
student_1 = advprog_student('Craig', 'Smith')
student_2 = advprog_student('Megan', 'Scott')
print(student_1.full_name())
print(student_2.full_name())
```

Here, `advprog_student` inherits methods like `full_name()` from `advprog_member`.

To fine-tune the `advprog_student` class, we adjust attributes:

```python
class advprog_student(advprog_member):
    role = "AdvProg student"
```

Now, creating a student instance reflects the updated role:

```python
student_1 = advprog_student('John', 'Smith')
print(student_1.role)
print(student_1.campus)
print(student_1.full_name())
```

Adding an `instance attribute` like `grade` using `super()`:

```python
class advprog_student(advprog_member):
    role = "AdvProg student"

    def __init__(self, first, last, grade):
        super().__init__(first, last)
        self.grade = grade
```

Instances of `advprog_student` now include the `grade` attribute:

```python
student_1 = advprog_student('John', 'Smith', 'B+')
print(student_1.email)
print(student_1.grade)
```

Creating another subclass, `advprog_instructor`, with additional methods:

```python
class advprog_instructor(advprog_member):
    role = "AdvProg instructor"

    def __init__(self, first, last, courses=None):
        super().__init__(first, last)
        self.courses = ([] if courses is None else courses)

    def add_course(self, course):
        self.courses.append(course)

    def remove_course(self, course):
        self.courses.remove(course)
```

Instances of `advprog_instructor` can manage courses:

```python
instructor_1 = advprog_instructor('Tom', 'Beuzen', ['511', '561', '513'])
print(instructor_1.full_name())
print(instructor_1.courses)
instructor_1.add_course('591')
instructor_1.remove_course('513')
print(instructor_1.courses)
```

---

# Getters, setters, deleters

For effective class management, Python provides getters, setters, and deleters. Consider a simplified `advprog_member` class:

```python
class advprog_member:
    # ... (unchanged)
```

Instances of `advprog_member` can be created and accessed:

```python
advprog_1 = advprog_member('Tom', 'Beuzen')
print(advprog_1.first)
print(advprog_1.last)
print(advprog_1.email)
print(advprog_1.full_name())
```

Utilizing a `@property` decorator for the `email` attribute:

```python
class advprog_member:
    # ... (unchanged)

    @property
    def email(self):
        return self.first.lower() + "." + self.last.lower() + "@advprog.com"
```

Now, changes to the `first` name reflect in the `email`:

```python
advprog_1 = advprog_member('Tom', 'Beuzen')
advprog_1.first = 'Tomas'
print(advprog_1.first)
print(advprog_1.last)
print(advprog_1.email)
print(advprog_1.full_name())
```

Introducing a `full_name` setter to update `first` and `last`:

```python
class advprog_member:
    # ... (unchanged)

    @full_name.setter
    def full_name(self, name):
        first, last = name.split(' ')
        self.first = first
        self.last = last
```

Setting the `full_name` now updates the attributes:

```python
advprog_1 = advprog_member('Tom', 'Beuzen')
advprog_1.full_name = 'Thomas Beuzen'
print(advprog_1.first)
print(advprog_1.last)
print(advprog_1.email)
print(advprog_1.full_name)
```

Finally, a `full_name` deleter:

```python
class advprog_member:
    # ... (unchanged)

    @full_name.deleter
    def full_name(self):
        print('Name deleted!')
        self.first = None
        self.last = None
```

Deleting the `full_name` attribute results in a cleanup:

```python
advprog_1 = advprog_member('Tom', 'Beuzen')
delattr(advprog_1, "full_name")
print(advprog_1.first)
print(advprog_1.last)
```

---

<!--
_class: titlepage
-->

# Modules and packages

---

<!--
_class: titlepage
-->

# Modules

---

<!--
_class: titlepage
-->

# Packages

---

<!--
_class: titlepage
-->

# :arrow_right: Modules and packages.<br>Object-oriented programming.<br>Classes, inheritance and polymorphism.
