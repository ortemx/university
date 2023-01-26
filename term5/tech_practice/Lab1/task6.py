from math import *
depositAmount: float = 300
depositPercentage: float = 2.5
monthlyMultiplier: float = pow((1 + depositPercentage / 100), 1/12)

numberOfMonths = ceil(log(1 + 200 / depositAmount, monthlyMultiplier))

print(f'сумма вклада: {depositAmount} тыс. рублей')
print(f'ставка: {depositPercentage} % годовых')
print(f'через {numberOfMonths} месяцев депозит увеличится на 200 тыс. рублей')



