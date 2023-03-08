a = int(input("a = "))
b = int(input("b = "))
s = 0
q = 0
while s + b <= a:
    s += b
    q += 1
print("q = ", q, "r = ", a - s)
