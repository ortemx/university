a = input()
b = input()
la = len(a)
lb = len(b)
dc = la + lb
a = a[::-1]
b = b[::-1]
for i in range(la, dc):
    a += '0'
for i in range(lb, dc):
    b += '0'
d = 0
c = [0 for i in range(dc)]
for i in range(0, dc):
    for k in range(0, i+1):
        c[i] = c[i]+int(a[k]) * int(b[i-k])
    c[i] = c[i] + d
    d = c[i] // 10
    c[i] = c[i] - d*10

c = c[::-1]
print(c)


