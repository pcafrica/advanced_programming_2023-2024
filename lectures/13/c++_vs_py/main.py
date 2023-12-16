import matrix_ops
import time
import numpy as np

# Create random matrices.
n = 500
mat1 = np.random.rand(n, n)
mat2 = np.random.rand(n, n)

# Benchmark C++ implementation (using pybind11).
start_time = time.time()
result_cpp = matrix_ops.matrix_multiply(mat1, mat2)
cpp_duration = time.time() - start_time
print(f"C++ implementation took {cpp_duration:.4f} seconds.")

def matrix_multiply_python(mat1, mat2):
    rows = len(mat1)
    cols = len(mat2[0])
    inner_dim = len(mat2)
    
    result = [[0 for _ in range(cols)] for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            for k in range(inner_dim):
                result[i][j] += mat1[i][k] * mat2[k][j]
    return result

# Benchmark Python implementation.
start_time = time.time()
result_python = matrix_multiply_python(mat1, mat2)
python_duration = time.time() - start_time
print(f"Python implementation took {python_duration:.4f} seconds.")

print(f"Speedup: {python_duration // cpp_duration}.")
