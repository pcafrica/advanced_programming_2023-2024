<!--
title: Lecture 03
paginate: true

_class: titlepage
-->

# Lecture 03
<br>

## Object oriented programming. Classes and access control in C++.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 10 Oct 2023

---

# Outline

- Introduction to Object-Oriented Programming (OOP)
- Classes and objects in C++
- Encapsulation and access control
- Class collaborations

---

<!--
_class: titlepage
-->

# Introduction to Object-Oriented Programming (OOP)

---

# What is OOP?

- OOP is a programming paradigm that revolves around objects.
- Objects represent instances of classes, encapsulating data and behavior.
- Key principles include encapsulation, inheritance, and polymorphism.

---

# Key principles of OOP

Object-Oriented Programming (OOP) is a programming paradigm that emphasizes the use of objects to represent real-world entities and concepts. It is based on several key principles:

- **Encapsulation**: Encapsulation bundles data (attributes) and the functions (methods) that operate on the data into a single unit called an object. This promotes data hiding and reduces the complexity of the code.
- **Inheritance**: Inheritance allows you to create new classes (derived or child classes) based on existing classes (base or parent classes). It enables code reuse and the creation of class hierarchies.
- **Polymorphism**: Polymorphism allows objects of different classes to be treated as objects of a common base class. It promotes code flexibility and the ability to work with objects at a higher level of abstraction.

---

# Advantages of OOP

OOP offers numerous advantages, including:

- **Modularity**: OOP encourages the division of a complex system into smaller, manageable objects, promoting code modularity and reusability.
- **Maintenance**: Objects are self-contained, making it easier to maintain and update specific parts of the code without affecting other parts.
- **Flexibility**: Inheritance and polymorphism provide flexibility, allowing you to extend and modify the behavior of classes without altering their existing code.
- **Readability**: OOP promotes code readability by organizing data and functions related to a specific object within a class.

---

<!--
_class: titlepage
-->

# Classes and objects in C++

---

# OOP in C++

- C++ is not (only) a OOP language.
- C++ is a multi-paradigm programming language that supports procedural, object-oriented, and generic programming.
- C++ allows developers to combine these paradigms effectively for various programming tasks.

---

# Creating objects (1/2)

In C++, objects are instances of classes. Here's an example of creating and using a `Car` object:

```cpp
class Car {
public:
    std::string make;
    std::string model;
    int year;

    void start_engine() {
        std::cout << "Engine started!" << std::endl;
    }
};
```

---

# Creating objects (2/2)

```cpp
Car my_car; // Creating an object of class Car.

my_car.make = "Toyota";
my_car.model = "Camry";
my_car.year = 2023;

my_car.start_engine(); // Invoking a method.
```

---

# Member variables

Member variables, also known as attributes or instance variables, store data within a class. In the Car class, make, model, and year are member variables that hold information about the car. These variables encapsulate the car's characteristics within the class.

---

# Member functions (or *methods*)

Member functions, or methods, define the behavior of a class. The start_engine method in the Car class initiates the car's engine. Methods encapsulate the actions or operations that can be performed on the object's data.

---

# `static` members

Static members in a class are shared among all instances of that class. They are declared using the `static` keyword and can be accessed using the class name rather than an object. Static members are useful for maintaining shared data or functionality across objects.

```cpp
class Circle {
public:
    static constexpr double PI = 3.14159265359; // Static constant shared by all Circle objects.
    double radius;

    double calculate_area() {
        return PI * radius * radius;
    }
};

Circle circle1, circle2;
circle1.radius = 5.0;
circle2.radius = 3.0;

double area1 = circle1.calculate_area(); // Accessing a non-static member.
double area2 = circle2.calculate_area();

double pi_value = Circle::PI; // Accessing a static member.
```

In this example, `PI` is a static constant shared among all Circle objects, while `radius` is an instance variable.

---

# Constructors

Constructors are special member functions that initialize objects when they are created. They have the same name as the class and can take arguments to set initial values for member variables. Constructors play a crucial role in object initialization and ensure that objects are in a valid state from the beginning.

```cpp
class Student {
public:
    Student(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    void display_info() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

Student student1("Alice", 20); // Creating an object and initializing it using a constructor.
student1.display_info();

```

In this example, the `Student` class has a constructor that takes name and age as parameters to initialize the object's state.

---

# Initializer list

An initializer list is used within a constructor to initialize member variables before entering the constructor body. It is a recommended practice, especially for initializing member objects or constants, as it can improve performance.

```cpp
class Rectangle {
public:
    Rectangle(double length, double width) : length(length), width(width) {
        // Constructor body (if needed).
    }

    double calculate_area() {
        return length * width;
    }

private:
    double length;
    double width;
};

Rectangle rectangle(5.0, 3.0); // Creating an object and initializing it using an initializer list.
double area = rectangle.calculate_area();
```

In this example, the `Rectangle` class uses an initializer list to set the length and width member variables during object creation.

---

# Copy constructor and copy assignment

Copy constructor and copy assignment operators allow you to create new objects by copying the values of existing objects of the same class. These operations are important for safely duplicating objects.

```cpp
class Book {
public:
    Book(std::string title, std::string author) : title(title), author(author) {}

    // Copy constructor
    Book(const Book& other) : title(other.title), author(other.author) {}

    // Copy assignment operator
    Book& operator=(const Book& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
        }
        return *this;
    }

    void display_info() {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
    
private:
    std::string title;
    std::string author;
};

Book book1("The Catcher in the Rye", "J.D. Salinger");
Book book2 = book1; // Copying using the copy constructor.
Book book3("To Kill a Mockingbird", "Harper Lee");
book3 = book1; // Copying using the copy assignment operator.
```

In this example, the `Book` class defines both a copy constructor and a copy assignment operator to enable safe copying of `Book` objects.

---

# Destructor

A destructor is a special member function that is called when an object goes out of scope or is explicitly deleted. It is responsible for releasing resources associated with the object, such as memory or file handles. Destructors play a vital role in resource management.

```cpp
class FileHandler {
public:
    FileHandler(std::string filename) : filename(filename) {
        file.open(filename);
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
        }
    }

private:
    std::string filename;
    std::ofstream file;
};

{
    FileHandler file("data.txt");
    // FileHandler object is automatically destroyed when it goes out of scope.
} // Destructor is called, and the file is closed.
```

In this example, the `FileHandler` class has a destructor that ensures the associated file is closed when the object is destroyed.

---

# Operator overloading
Operator overloading allows you to define custom behaviors for operators when used with objects of your class. This feature provides a way to make objects of your class work with operators just like built-in types.

```cpp
class Complex {
public:
    double real;
    double imag;

    Complex operator+(const Complex& other) {
        Complex result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }
};

Complex a{2.0, 3.0};
Complex b{1.0, 2.0};
Complex c = a + b; // Using the overloaded '+' operator.
```

In this example, the `Complex` class overloads the `+` operator to allow addition of complex numbers.

---

# The `inline` directive

---

<!--
_class: titlepage
-->

# Encapsulation and access control

---

# Data encapsulation

Data encapsulation is a fundamental concept in OOP that involves bundling data (attributes) and methods (functions) that operate on that data into a single unit called an object. Encapsulation helps hide the internal details of an object and exposes only the necessary functionality through well-defined interfaces.

```cpp
class BankAccount {
public:
    BankAccount(std::string accountHolder, double balance) : accountHolder(accountHolder), balance(balance) {}

    void deposit(double amount) {
        // Perform validation and update balance.
        balance += amount;
    }

    double get_balance() const {
        return balance;
    }

private:
    std::string accountHolder;
    double balance;
};
```

In this example, the `BankAccount` class encapsulates the account holder's name and balance. The `deposit` method allows controlled access to modify the balance, and the `get_balance` method provides read-only access to the balance.

---

# Access specifiers

C++ provides access specifiers (public, private, and protected) to control the visibility and accessibility of class members (variables and methods). These access specifiers enforce encapsulation and access control within the class.

- `public`: Members declared as public are accessible from any part of the program. They form the class's public interface.
- `private`: Members declared as private are not accessible from outside the class. They are used for internal implementation details.
- `protected`: Members declared as protected are accessible within the class and by derived classes (in inheritance scenarios).

```cpp
class MyClass {
public:
    int publicVar;    // Public member variable.
    void publicFunc() // Public member function.
    {
        // ...
    }

private:
    int privateVar;    // Private member variable.
    void privateFunc() // Private member function.
    {
        // ...
    }
};
```
In this example, `publicVar` and `publicFunc` are accessible from outside the class, while `privateVar` and `privateFunc` are only accessible within the class.

---

# `class` vs. `struct`

In C++, both `class` and `struct` are used to define classes. The only difference between them is the default access specifier:

- In a `class`, members are private by default, meaning they are not accessible from outside the class without explicit permission.
- In a `struct`, members are public by default, meaning they are accessible from outside the class without restrictions.

```cpp
class MyClass {
    int x; // Private by default.
public:
    int y; // Public.
};

struct MyStruct {
    int a; // Public by default.
private:
    int b; // Private.
};
```

---

# Getter and setter methods

Getter and setter methods, also known as accessors and mutators, are used to control access to private member variables. Getter methods allow reading the values of private variables, while setter methods enable modifying those values in a controlled manner. They are commonly used for encapsulation and access control.

---

# `friend` classes

---

<!--
_class: titlepage
-->

# Class collaborations

--- 

# Relationships between classes

---

# Composition vs. inheritance

---

# Aggregation and composition

---

# Class views (*proxies*)

---

<!--
_class: titlepage
-->

# :arrow_right: Inheritance + polymorphism
