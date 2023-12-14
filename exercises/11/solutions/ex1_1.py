#!/usr/bin/env python3

import numpy as np

n = 5

# Create a 2D array with random integers.
matrix = np.random.randint(1, 11, size=(n, n))

# Extract second row, third column, and diagonal elements.
second_row = matrix[1, :]
third_column = matrix[:, 2]
diagonal = np.diag(matrix)

# Reshape into a 1D array.
reshaped_array = matrix.reshape((1, n * n))
