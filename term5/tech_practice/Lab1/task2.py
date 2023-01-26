from random import *

x: int = int(input("Введите x "))
a: int = int(input("Введите a "))
d: int = int(input("Введите d "))

x: int = 2
a: int = -1
d: int = 2

print("первый член = ", a + 3, ", разность = ", d * 2, ", x = ", x, sep="")
print(x - (a + 3) % (d * 2) < 0.0001 and (a + 3) <= x)

