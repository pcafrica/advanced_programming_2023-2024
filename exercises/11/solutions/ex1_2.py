#!/usr/bin/env python3

import numpy as np

n = 3

# Generate two 3x3 matrices.
matrix1 = np.random.randint(1, 11, size=(n, n))
matrix2 = np.random.randint(1, 11, size=(n, n))

# Element-wise multiplication.
element_wise_product = matrix1 * matrix2

# Matrix-matrix multiplication.
matrix_product = matrix1 @ matrix2 # Or: np.dot(matrix1, matrix2)

# Create a 3x3 matrix and compute its inverse and determinant.
matrix3 = np.random.rand(n, n)
inv_matrix3 = np.linalg.inv(matrix3)
det_matrix3 = np.linalg.det(matrix3)
