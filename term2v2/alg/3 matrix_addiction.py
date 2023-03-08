print("enter dimension A(n x m)")
n = int(input("n = "))
m = int(input("m = "))

A = [[0 for j in range(m)] for i in range(n)]
B = [[0 for j in range(m)] for i in range(n)]
for i in range(n):
    for j in range(m):
        A[i][j] = float(input())
for i in range(n):
    for j in range(m):
        B[i][j] = float(input())
for i in range(n):
    for j in range(m):
        A[i][j] += B[i][j]
for i in range(n):
    print(A[i])
input()
