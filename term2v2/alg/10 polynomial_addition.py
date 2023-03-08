n = int(input("deg f(x) : "))
a = [float(input(f"coefficient at x^{n-i-1} : "))for i in range(n)]


m = int(input("deg g(x) : "))
b = [float(input(f"coefficient at x^{m-i-1} : "))for i in range(m)]

c = [0] * max(n, m)

n = n - m
if n == 0:
    for i in range(len(c)):
        c[i] = a[i] + b[i]
else:
    if n > 0:
        for i in range(n):
            c[i] = a[i]
        for i in range(len(b)):
            c[i+n] = a[i+n] + b[i]
    else:
        for i in range(-n):
            c[i] = b[i]
        for i in range(len(a)):
            c[i-n] = a[i] + b[i-n]

print(c)
