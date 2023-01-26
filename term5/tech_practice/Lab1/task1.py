from random import *

# a: int = randint(-10, 10)
# b: int = randint(-10, 10)
# c: int = randint(-10, 10)
# d: int = randint(-10, 10)
# e: int = randint(-10, 10)

a = int(input("Введите a "))
b = int(input("Введите b "))
c = int(input("Введите c "))
d = int(input("Введите d "))
e = int(input("Введите e "))

avg: float = (a + b + c + d + e) / 5

maxNumber = max(a, b, c, d, e)
print(avg, maxNumber, avg + maxNumber, avg - maxNumber)
