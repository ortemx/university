# x = [-1, 0, 3]  # значения случайной величины
# p = [0.4, 0.4, 0.2]  # соответствующие вероятности

# # вычисление математического ожидания
# E_x = sum([x[i] * p[i] for i in range(len(x))])

# # вычисление дисперсии
# E_x2 = sum([x[i]**2 * p[i] for i in range(len(x))])
# D_x = E_x2 - E_x**2

# print("Математическое ожидание: ", E_x)
# print("Дисперсия: ", D_x)


import numpy as np
from scipy.stats import norm

# Задаем параметры распределения
mu = 80
n = 600
sigma = 10 / np.sqrt(n)  # дисперсия равна 100, так как Var(xi) = sigma^2 = 100

# Вычисляем вероятность
p = norm.cdf(1.5, loc=mu, scale=sigma) - norm.cdf(-1.5, loc=mu, scale=sigma)

print(f"Вероятность отклонения среднего арифметического на величину меньшую 1,5: {p:.2%}")