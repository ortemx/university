import math


def P(n, k, p, q):
    numerator = math.factorial(n) * pow(p[0], k) * pow(q[0], (n - k))

    denomerator = math.factorial(k) * math.factorial(n - k) * pow(p[1], k) * pow(q[1], (n - k))

    temp: int = math.gcd(numerator, denomerator)
    numerator /= temp
    denomerator /= temp
    print(numerator, denomerator, numerator/denomerator)


def fi(n, p, q, k):

    x = (k - n * p) / math.sqrt(n * p * q)

    if x > 5:
        return 0
    return 1 / math.sqrt(2 * math.pi) * math.exp(- (x * x) / 2)


n = 46
k = 36
p = (88, 100)
q = (p[1]-p[0], p[1])

P(n, k, p, q)

print(1 / math.sqrt(n * p[0]/p[1] * q[0]/q[1]) * fi(n, p[0]/p[1], q[0]/q[1], k))
