# Part 2: Programming exercise

## Objective
Develop a numerical solver for ordinary differential equations (ODEs) in C++ and integrate it with Python using pybind11.

---

## Mathematical background
The Forward Euler method is a widely used numerical scheme for solving ordinary differential equations (ODEs).

Consider a system of ODEs represented as:

$$
\begin{align*}
\frac{\mathrm{d}\mathbf{z}}{\mathrm{d}t} &= \mathbf{f}(t, \mathbf{z}), \\
\mathbf{z}(t_0) &= \mathbf{z}_0,
\end{align*}
$$

where $t$ ranges from $t_0$ to $t_f$.

Given a timestep $\Delta t$, the Forward Euler method updates the solution at the next discrete time step, $t_{i+1}$, using the formula:

$$
\mathbf{z}_{i+1} = \mathbf{z}_i + \Delta t \cdot \mathbf{f}(t_i, \mathbf{z}_i).
$$

In this formula, $\mathbf{z}_i$ represents the state of the system at the discrete time $t_i$, and $\mathbf{f}(t_i, \mathbf{z}_i)$ is the rate of change of the system at time $t_i$.


The Lotka-Volterra equations are widely used in ecological studies to describe the dynamics of biological systems in which two species interact, one as a predator and the other as prey. The Lotka-Volterra system of ODEs reads

$$
\begin{align*}
\frac{\mathrm{d}x}{\mathrm{d}t} &= \alpha x - \beta xy, \\
\frac{\mathrm{d}y}{\mathrm{d}t} &= \delta xy - \gamma y.
\end{align*}
$$

Here,
- $x$ represents the number of prey (for example, rabbits),
- $y$ represents the number of predators (for example, foxes),
- $\alpha, \beta, \gamma$, and $\delta$ are positive real constants that describe the interaction between the prey and the predators.

---

## Tasks
The goal is to implement the Forward Euler method for a generic ODE, and to use it to solve the Lotka-Volterra equations given the following parameters:

$$
\begin{alignat*}{2}
\alpha &= 0.1 &\quad& \text{(Prey birth rate.)} \\
\beta &= 0.02 && \text{(Predation rate.)} \\
\gamma &= 0.3 && \text{(Predator death rate.)} \\
\delta &= 0.01 && \text{(Predator reproduction rate.)} \\
\\
x_0 &= 40 && \text{(Prey.)} \\
y_0 &= 9 && \text{(Predators.)} \\
\\
t_0 &= 0 && \text{(Initial time.)} \\
t_f &= 200 && \text{(Final time.)} \\
\Delta t &= 0.05 && \text{(Timestep.)} \\
\end{alignat*}
$$

1. **C++ codebase**
   1. Design a class `ForwardEuler` to encapsulate the solver.
   2. Use an integral template parameter `n` to specify the number of state variables in the ODE.
   3. Store the initial value in a `std::array<double, n>` and the solution at each timestep in a `std::vector<std::array<double, n>>`.
   4. The class should represent the ODE as a
   ```cpp
   std::function<std::array<double, n>(double, std::array<double, n>)>
   ```
   and should store all the parameters related to the Forward Euler method.
   5. In the `main()`, define the Lotka-Volterra system as a lambda function and solve it.

2. **Configuration and compilation**
   1. Develop a CMake script for easy compilation of the C++ library.
   2. Provide clear instructions on compiling the library.

3. **Python bindings using pybind11**
   1. Bind the C++ functions, classes and their methods to Python.
   2. Ensure the Python interface is user-friendly and adheres to Python conventions.
   3. Create Python scripts to test the functionality of the solver through the bindings.
   4. Visualize the solution (number of prey and predators) as a function of time.
   5. Validate and compare the results against the [`solve_ivp` function](https://docs.scipy.org/doc/scipy/reference/generated/scipy.integrate.solve_ivp.html) from the Python module `scipy.integrate`.

4. **(Bonus) validation and comparison**
   1. Design benchmarks to compare performance metrics between the C++ and Python implementations.
   2. Instead of using a lambda function, consider creating a new abstract class `ODEProblem` working as a functor, and derive a subclass `LotkaVolterra` storing all the related parameters and returning the evaluation of $\mathbf{f}(t, [x, y])$.
