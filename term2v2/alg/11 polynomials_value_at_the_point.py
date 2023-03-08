n = int(input("enter deg(P[x]) ")) + 1
p = 0
c = float(input("enter point "))
for i in range(n):
    p = p * c + float(input(f"enter coefficient at x^{n-i-1} "))
print(p)
