#!/usr/bin/env python3

from scipy.sparse import diags
from scipy.sparse.linalg import spsolve
from scipy.linalg import norm
import numpy as np

# Define a 100x100 sparse tridiagonal matrix.
diagonals = [2 * np.ones(100), -1 * np.ones(99), -1 * np.ones(99)]
A = diags(diagonals, [0, -1, 1], format='csr')

# Define b and x_ex.
x_ex = np.ones(100)
b = A @ x_ex

# Solve the linear system Ax = b.
x = spsolve(A, b)

# Compute norms of the residual and error.
residual = b - A @ x
error = x - x_ex

norm1_res = norm(residual, 1)
norm2_res = norm(residual, 2)
norm_inf_res = norm(residual, np.inf)

norm1_err = norm(error, 1)
norm2_err = norm(error, 2)
norm_inf_err = norm(error, np.inf)
