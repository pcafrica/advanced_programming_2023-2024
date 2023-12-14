<!--
title: Homework 03
paginate: true

_class: titlepage
-->

# Homework 03
<br>

## Implementation of a Scientific Computing Toolbox
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa, Marco Feder

###### Due date: 12 Jan 2024

---

# Objective

This assignment builds on Homework 02, integrating new topics like:
- Python and built-in data types.
- Object-oriented programming in Python.
- Python modules and packages.
- Use of Python ecosystem for scientific computing (NumPy, SciPy, Matplotlib, seaborn, pandas)
- C++ and Python integration using pybind11.

Your task is to enhance the C++ scientific computing toolbox developed in Homework 02 with Python bindings and additional functionalities.

Build your Homework 03 on **module A)** and **one module among B), C), D)** from Homework 02, of your choice.

---

# Tasks (1/2)

1. **Python bindings using pybind11**:
   - Create Python bindings for the C++ modules (Statistics and Interpolation, Numerical integration, or ODE) using pybind11.
   - Ensure Python users can seamlessly use the functionalities of these modules.

2. **Data analysis and visualization in Python**:
   - Utilize pandas and numpy for data manipulation and scipy for advanced computations.
   - Add functionality to visualize results using a Python plotting library (e.g., Matplotlib, seaborn).
   - Demonstrate this with examples in a Jupyter Notebook.

---

# Tasks (2/2)

3. **Object-oriented Python extensions**:
   - Design Python classes that complement your C++ modules, showcasing OOP principles.
   - Implement features that leverage Python’s flexibility, like dynamic typing, decorators, magic methods, and context management.

4. **Advanced Python-C++ integration**:
   - Demonstrate integration where Python and C++ interact more complexly, like C++ callbacks being used in Python or vice versa.
   - Explore efficiency gains from this hybrid approach in data-intensive tasks.

---

# Requirements

- **Compatibility**: Ensure Python bindings are compatible with the C++ codebase from Homework 02.
- **Documentation**: Update the README with instructions on using the Python interface, including installation of pybind11 and any dependencies.
- **Examples**: Provide Python scripts or Jupyter Notebooks demonstrating the use of the toolbox in real-world scenarios.
- **Testing**: Include tests verifying that the Python interface correctly interacts with the C++ modules.

---

# Evaluation grid

1. **Functionality** (up to **10 points**): Python bindings work correctly with all C++ modules.
2. **Integration** (up to **10 points**): Seamless integration between Python and C++ components.
3. **Documentation and examples** (up to **5 points**): Clear, instructive documentation and practical examples.
4. **Code quality and testing** (up to **5 points**): Clean, well-organized code with adequate tests.
