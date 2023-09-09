import numpy as np


def gaussian_elimination(A, b):
    n = len(b)
    for i in range(n):
        max_row = i
        for j in range(i+1, n):
            if abs(A[j, i]) > abs(A[max_row, i]):
                max_row = j
        A[[i, max_row]] = A[[max_row, i]]
        b[[i, max_row]] = b[[max_row, i]]

        if abs(A[max_row, i]) < 1e-10:
            # Вырожденность матрицы
            raise ValueError("Матрица вырождена")

        for j in range(i+1, n):
            k = A[j, i] / A[i, i]
            A[j, i:] -= k * A[i, i:]
            b[j] -= k * b[i]

    x = np.zeros(n, dtype=float)
    for i in range(n-1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i+1:], x[i+1:])) / A[i, i]

    return x

 
# Пример использования
A = np.array([[2, 3, -1],
              [1, -1, 6],
              [6, -2, 1]], dtype=float)

A_copy  = A.copy()
b = np.array([7, 14, 11], dtype=float)

x = gaussian_elimination(A, b)
print("x =", x)

print("check solution:\nb =", np.dot(A_copy, x))
