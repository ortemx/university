a = int(input("a = "))
b = int(input("b = "))

print(f"НОД({a},{b})=", end="")
if a < b:
    pass
    # a, b = b, a

while a != b:
    if a > b:
        a -= b
    else:
        b -= a
# 4354560 120
print(b)
input()
