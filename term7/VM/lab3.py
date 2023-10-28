"""Jacoby method for linear equation
"""

import numpy as np

def Jacoby(A, b, eps=1e-4, max_iter=100):
    # if not is_converged(A):
    #     return (b, max_iter)
    n = len(b)
    x = np.zeros(n)
    # первое приближение
    x_1 = -(-b[0]) / A[0, 0]
    x_2 = -(A[1, 0] * x_1 - b[1]) / A[1, 1]
    x_3 = -(A[2, 0] * x_1 + A[2, 1] * x_2 - b[2]) / A[2, 2]
    print(x_1, x_2, x_3)
    iter_num = max_iter  
    for i in range(max_iter - 1):
        # x_1 = -(A[0, 1] * x[1] + A[0, 2] * x[2] - b[0]) / A[0, 0]
        # x_2 = -(A[1, 0] * x[0] + A[1, 2] * x[2] - b[1]) / A[1, 1]
        # x_3 = -(A[2, 0] * x[0] + A[2, 1] * x[1] - b[2]) / A[2, 2]
        x_1 = -(A[0, 1] * x[1] + A[0, 2] * x[2] - b[0]) / A[0, 0]
        print(A[1, 0], x_1, A[1, 2], x[2], b[1], A[1, 1])
        x_2 = -(A[1, 0] * x_1 + A[1, 2] * x[2] - b[1]) / A[1, 1]
        x_3 = -(A[2, 0] * x_1 + A[2, 1] * x_2 - b[2]) / A[2, 2]
        x = [x_1, x_2, x_3]
        print(x)
        if np.linalg.norm(np.dot(A, x) - b) < eps:
            iter_num = i
            break

    return (x, iter_num, np.linalg.norm(np.dot(A, x) - b))


def is_converged(A):
    for i in range(len(A)):
        sum = 0
        for j in range(len(A)):
            if i != j:
                sum += abs(A[i][j])
        if (abs(A[i][i]) <= sum):
            return False
    return True
    
A = np.array([[3, -2, 4],
              [2, -1, -1],
              [3, 4, -2]])
b = np.array([11, 4, 11])


# A = np.array([[10, 0, 0],
#               [0, 11, 2],
#               [1, 0, 5]])
# b = np.array([10, 15, 11])


# A = np.array([[4, 1, 2],
#               [3, 5, 1],
#               [1, 1, 3]])
# b = np.array([4, 7, 3])

x = Jacoby(A, b)
print(is_converged(A))
print("x =", x)
