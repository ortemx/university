from random import randint
from time import time

dim: int = 500
A = [[randint(0, dim) for j in range(dim)] for i in range(dim)]

B = [[randint(0, dim) for j in range(dim)] for i in range(dim)]

C = [[0 for j in range(dim)] for i in range(dim)]


start = time()
for i in range(0, dim):
    for j in range(0, dim):
        C[i][j] = 0
        for k in range(0, dim):
            C[i][j] += A[i][k] * B[k][j]
            pass

print(time() - start)
# for i in range(0, dim):
#     for j in range(0, dim):
#         print(A[i][j], "\t", end='')
#     print()
# print()
#
# for i in range(0, dim):
#     for j in range(0, dim):
#         print(B[i][j], "\t", end='')
#     print()
# print()
#
# for i in range(0, dim):
#     for j in range(0, dim):
#         print(C[i][j], "\t", end='')
#     print()
