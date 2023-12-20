import numpy as np
import time
import eigen_ops

def log_execution_time(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(f"{func.__name__} executed in {end - start} seconds.")
        return result
    return wrapper

@log_execution_time
def test_eigen_product(A, B):
    eigen_product = eigen_ops.matrix_multiply(A, B)

@log_execution_time
def test_eigen_inversion(A, B):
    eigen_inversion = eigen_ops.matrix_invert(A)

@log_execution_time
def test_numpy_product(A, B):
    numpy_product = np.matmul(A, B)

@log_execution_time
def test_numpy_inversion(A, B):
    numpy_inversion = np.linalg.inv(A)

n = 1000
A = np.random.rand(n, n)
B = np.random.rand(n, n)

test_eigen_product(A, B)
test_eigen_inversion(A, B)
test_numpy_product(A, B)
test_numpy_inversion(A, B)
