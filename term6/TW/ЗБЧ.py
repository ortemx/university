import math

# Вычисление математического ожидания
def calc_expected_value():
    return -50 * (-50**2/7500 + 100**2/7500)

# Вычисление среднеквадратического отклонения
def calc_standard_deviation():
    n = 70
    s_squared = 1/70 * (1/10000 * (100**4 - 50**4) + 1/4 * (100**2 - 50**2))
    return math.sqrt(n) * math.sqrt(s_squared)

# Вычисление вероятности P(Q >= 4800)
def calc_probability():
    Q = -23333.33
    sigma = 236.8
    z = (4800 - Q) / sigma
    return 1 - 0.5 * (1 + math.erf(z / math.sqrt(2)))

print("Средний заряд отдельного аккумулятора:", calc_expected_value())
print("Среднеквадратическое отклонение:", calc_standard_deviation())
print("Вероятность P(Q >= 4800):", calc_probability())
print("Вероятность P(Q >= 4800): {:.4f}".format(calc_probability()))
