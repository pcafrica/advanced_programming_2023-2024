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
    return eigen_ops.matrix_multiply(A, B)

@log_execution_time
def test_eigen_inversion(A):
    return eigen_ops.matrix_invert(A)

@log_execution_time
def test_numpy_product(A, B):
    return np.matmul(A, B)

@log_execution_time
def test_numpy_inversion(A):
    return np.linalg.inv(A)

n = 1000
A = np.random.randint(0, 1001, size=(n, n))
B = np.random.randint(0, 1001, size=(n, n))

test_eigen_product(A, B)
test_eigen_inversion(A)
test_numpy_product(A, B)
test_numpy_inversion(A)
