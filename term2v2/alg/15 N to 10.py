def get_system_base(n: int) -> str:
    if n == 0:
        return SYSTEM_BASE[0]
    n = abs(n)
    system_base = ""
    while n != 0:
        system_base = SYSTEM_BASE[n % 10] + system_base
        n //= 10

    return system_base


SYSTEM_BASE = {
    0: "₀",
    1: "₁",
    2: "₂",
    3: "₃",
    4: "₄",
    5: "₅",
    6: "₆",
    7: "₇",
    8: "₈",
    9: "₉",
}

n = int(input("enter base of the number system: "))
m = (int (input("enter number length: ")))
s = 0

for i in range(m):
    a = input(f'enter a{get_system_base(i)}')
    if a == 'A':
        s += 10 * n ** (m - 1 - i)
    elif a == 'B':
        s += 11 * n ** (m - 1 - i)
    elif a == 'C':
        s += 12 * n ** (m - 1 - i)
    elif a == 'D':
        s += 13 * n ** (m - 1 - i)
    elif a == 'E':
        s += 14 * n ** (m - 1 - i)
    elif a == 'F':
        s += 15 * n ** (m - 1 - i)
    else:
        s += int(a) * n ** (m - 1 - i)
print(s)

