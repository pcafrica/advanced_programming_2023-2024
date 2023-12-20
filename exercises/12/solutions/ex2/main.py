import newton_solver
import cmath

# Function f(x) = x^2 - 1 = 0 and its derivative.
def function(x):
    return x * x - 1

def derivative(x):
    return 2 * x

# Create a NewtonSolver instance for real functions and find the root.
x0 = 0.5
solver_real = newton_solver.NewtonSolverDouble(function, derivative, x0, 0, 10)

try:
    root = solver_real.solve()
    print(f"Approximate root: {root}")
except RuntimeError as e:
    print("Error: ", str(e))

# Create a NewtonSolver instance for complex functions and find the root.
x0 = complex(0.5, 0.5)
solver_complex = newton_solver.NewtonSolverComplex(function, derivative, x0)

try:
    root = solver_complex.solve()
    print(f"Approximate root: {root}")
except RuntimeError as e:
    print("Error: ", str(e))
