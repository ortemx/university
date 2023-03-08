a = int(input("a = "))
b = int(input("b = "))
print(f"НОД({a},{b})=", end="")
if a < b:
    a, b = b, a

while a % b != 0:
    a, b = b, a % b
print(abs(b))
input()


