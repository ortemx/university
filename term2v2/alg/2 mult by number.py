print("dimension of matrix A(n x m)")
n = int(input("n = "))
m = int(input("m = "))
A = [[0 for j in range(m)] for i in range(n)]
print("A:")
for i in range(n):
    for j in range(m):
        A[i][j] = float(input())
for i in range(n):
    print(A[i])
print("enter alpha:")
alpha = float(input())

for i in range(n):
    for j in range(m):
        A[i][j] *= alpha
print("alpha * A:")
for i in range(n):
    print(A[i])
input()
