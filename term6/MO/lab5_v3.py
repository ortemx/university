from pulp import *

# исходные данные
capital_investments = 5
utility_matrix = [[0.0, 2.0, 2.4, 3.0, 3.6, 4.4],
                  [0.0, 1.5, 2.0, 2.8, 4.0, 5.1],
                  [0.0, 2.3, 2.8, 3.4, 4.8, 5.6]]

num_enterprises = len(utility_matrix)

# создаем объект задачи
prob = LpProblem("Investment Problem", LpMaximize)

# создаем переменные решения
investments = LpVariable.dicts("Investment", range(num_enterprises), lowBound=0, cat='Continuous')

# создаем функцию цели
prob += lpSum([utility_matrix[i][j] * investments[i] for i in range(num_enterprises) for j in range(min(capital_investments + 1, len(utility_matrix[i])))])

# добавляем ограничения
prob += lpSum([investments[i] for i in range(num_enterprises)]) == capital_investments
for i in range(num_enterprises):
    prob += investments[i] <= capital_investments

# решаем задачу
prob.solve()

# выводим результаты
print("Количество капитала, необходимое для вложения в каждое предприятие:")
for i in range(num_enterprises):
    print(f"Предприятие {i+1}: {investments[i].value()}")

print(f"Итоговая прибыль: {value(prob.objective)} миллионов долларов")
