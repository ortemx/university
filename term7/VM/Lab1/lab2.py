"""метод прогонки
"""

import numpy as np

def tridiagonal_solver(A, b):
    n = len(b)

    for i in range(n):
        diagonal_sum = np.sum(np.abs(A[i, :])) - np.abs(A[i, i])
        if np.abs(A[i, i]) <= diagonal_sum:
            raise ValueError("Матрица не удовлетворяет условию диагонального преобладания")

    
    p = np.zeros(n-1)
    q = np.zeros(n)

    p[0] = -A[0, 1] / A[0, 0]
    # if 0 < p[0] < 1:
        
    q[0] = b[0] / A[0, 0]

    for i in range(1, n-1):
        p[i] = -A[i, i+1] / (A[i, i] + A[i, i-1] * p[i-1])
        q[i] = (b[i] - A[i, i-1] * q[i-1]) / (A[i, i] + A[i, i-1] * p[i-1])

    q[n-1] = (b[n-1] - A[n-1, n-2] * q[n-2]) / (A[n-1, n-1] + A[n-1, n-2] * p[n-2])

    x = np.zeros(n)
    x[n-1] = q[n-1]

    for i in range(n-2, -1, -1):
        x[i] = p[i] * x[i+1] + q[i]

    return x


A = np.array([[2, -1, -0, 0, 0],
              [-3, 8, -1, 0, 0],
              [0, -5, 12, 2, 0],
              [0, 0, -6, 18, -4],
              [0, 0, 0, -5, 10]])

b = np.array([-25, 72, -69, -156, 20])
x = tridiagonal_solver(A, b)

print("x =", x)

print("check solution:\nb =", np.dot(A, x))
