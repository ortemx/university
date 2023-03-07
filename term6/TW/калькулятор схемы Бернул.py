import math


def P(n, k, p, q):
    numerator = math.factorial(n) * pow(p[0], k) * pow(q[0], (n - k))

    denomerator = math.factorial(k) * math.factorial(n - k) * pow(p[1], k) * pow(q[1], (n - k))

    temp: int = math.gcd(numerator, denomerator)
    numerator /= temp
    denomerator /= temp
    print(numerator, denomerator, numerator/denomerator)
    return numerator / denomerator


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


n = 46
k = 36
p = (88, 100)
q = (p[1]-p[0], p[1])

sum = 0
for k in range (23, 47):
    pass
    # sum += P(n, k, p, q)

print("sum = ", sum)


def laplas(n, p, q, k):
   return 1 / math.sqrt(n * p * q) *  fi (n, p, q, k)

def pauson(n, p, k):
    lmb = n * p    
    return pow(lmb, k) * math.exp(-lmb) / math.factorial(k)

def bern(n, p, q, k):
    return math.factorial(n) / (math.factorial(k) * math.factorial(n - k)) * math.pow(p, k) * math.pow(q, n - k)

print("laplas = ", laplas(1000, 0.003, 0.997, 3))
print("pauson = ", pauson(1000, 0.003, 3))

print("laplas = ", laplas(100, 0.01, 0.99, 0) +  laplas(100, 0.01, 0.99, 1))
print("pauson = ", pauson(100, 0.01, 0) + pauson(100, 0.01, 1))

print("bernuli = ", bern(3, 0.6, 0.4, 3))

sum = 0
for i in range(0, 4):
    sum += bern(3, 0.6, 0.4, i)
    print(f"bernuli({3}, {i}) = {bern(3, 0.6, 0.4, i)}")
print("sum =", sum)

sum = 0
for i in range(0, 4):
    sum += bern(3, 0.7, 0.3, i)
    print(f"bernuli({3}, {i}) = {bern(3, 0.7, 0.3, i)}")
print("sum =", sum)


p = [0.0017, 0.0544, 0.1905, 0.0741]
q = [1-p[i] for i in range(4)]
print(q)

s = 0
for i in p:
    s += i
print(s)

print(0.216*(0.027 + 0.189 + 0.441) + 0.432*(0.027 + 0.189) + 0.288 * 0.027)