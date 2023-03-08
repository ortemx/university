from math import sqrt
n = (int(input("enter n: ")) - 1) // 2
a = [2*i + 3 for i in range(n)]

for p in range(n):
    if a[p]:
        print(a[p], end=' ')
        for j in range(p + a[p], n, a[p]):
            a[j] = 0

print()

n = int(input("enter n: "))
b = [True for i in range(n)]
for p in range(2, n):
    if b[p]:
        print(p, end=' ')
        for j in range(p * p, n, p):
            b[j] = False
print(b)
input()