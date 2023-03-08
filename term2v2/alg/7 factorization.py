n = int(input("n = "))
i = 2
while n >= i ** 2:
    if n % i == 0:
        print(i, end=' ')
        n //= i
    else:
        i += 1
print(n)
input()
