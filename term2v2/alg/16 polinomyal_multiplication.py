# f(x) = x^5-7x^3 + 12x - 4
# g(x) = x^3 + 12x^2 + 7
a = [1, 12, 0, 7]
b = [1, 0, -7, 0, 12, -4]
#b = [3, 4, 6, 0, -7]
#a = [9, 0, -5, 2, -1]
# 27 x^8 + 36 x^7 + 39 x^6 - 14 x^5 - 88 x^4 + 8 x^3 + 29 x^2 - 14 x + 7
#a = [7, 0, 2, -6]
#b = [-4, 5]
c = [0 for i in range(len(a) + len(b) - 1)]

for i in range(len(a)):
    for j in range(len(b)):
        c[i+j] += a[i] * b[j]

print(c)

