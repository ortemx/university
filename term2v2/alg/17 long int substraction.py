raw_a = '10'
raw_b = '11'
n = len(raw_a)
m = len(raw_b)
a = [int(raw_a[i]) for i in range(n)]
b = [int(raw_b[i]) for i in range(m)]

flag = False
if n == m:
    is_equal = True
    for i in range(n):
        if a[i] > b[i]:
            is_equal = False
            print("a > b")
            break
        elif a[i] < b[i]:
            is_equal = False
            flag = True
            break
    if is_equal:
        print("a = b")
elif n > m:
    print("a > b")
else:
    flag = True

if flag:
    print("b > a")
    a, b = b, a
    n, m = m, n
    print("-", end='')

for i in range(m, n):
    b = [0] + b

for i in range(n-1, -1, -1):
    if a[i] >= b[i]:
        a[i] -= b[i]
    else:
        j = i - 1
        while a[j] == 0:
            a[j] = 9
            j -= 1
        a[j] -= 1
        a[i] = a[i] + 10 - b[i]
print(a)

