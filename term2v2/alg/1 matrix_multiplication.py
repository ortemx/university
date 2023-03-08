print("dimension of matrix A(n x k)")
n = int(input("n = "))
k = int(input("k = "))
m = int(input("number of columns of B = "))
# A = [[random.randint(0, 9) for j in range(k)] for i in range(n)]
# B = [[random.randint(0, 9) for j in range(m)] for i in range(k)]
A = [[0 for j in range(k)] for i in range(n)]
B = [[0 for j in range(m)] for i in range(k)]
for i in range(n):
    for j in range(k):
        A[i][j] = float(input())
for i in range(k):
    for j in range(m):
        B[i][j] = float(input())


print("A:")
for i in range(n):
    print(A[i])
print("B:")
for i in range(k):
    print(B[i])

C = [[0 for j in range(m)] for i in range(n)]

for i in range(n):
    for j in range(m):
        for p in range(k):
            C[i][j] += A[i][p] * B[p][j]
print("C:")
for i in range(n):
    print(C[i])
input()
