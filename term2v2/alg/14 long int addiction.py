raw_a = input("a = ")
raw_b = input("b = ")

if len(raw_a) < len(raw_b):
    temp = raw_a
    raw_a = '0' + raw_b
    raw_b = temp
else:
    raw_a = '0' + raw_a

a = [int(raw_a[i]) for i in range(len(raw_a))]
b = [int(raw_b[i]) for i in range(len(raw_b))]
diff = abs(len(a) - len(b))
for i in range(len(b) - 1, -1, -1):
    a[diff + i] += b[i]
    if a[diff + i] >= 10:
        a[diff + i] -= 10
        a[diff + i - 1] += 1
for i in range(diff-1, 0, -1):
    if a[i] >= 10:
        a[i] -= 10
        a[i-1] += 1
    else:
        break
print(a)

