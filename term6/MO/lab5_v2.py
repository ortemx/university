import itertools

capital_investments = 5
utility_matrix = [[0.0, 2.0, 2.4, 3.0, 3.6, 4.4],
                  [0.0, 1.5, 2.0, 2.8, 4.0, 5.1],
                  [0.0, 2.3, 2.8, 3.4, 4.8, 5.6]]

num_enterprises = len(utility_matrix)
max_utility = 0.0
best_investments = None

for investments in itertools.product(range(capital_investments+1), repeat=num_enterprises):
    if sum(investments) != capital_investments:
        continue
    total_utility = sum(utility_matrix[i][investments[i]] for i in range(num_enterprises))
    if total_utility > max_utility:
        max_utility = total_utility
        best_investments = investments

print(f"Количество капитала, необходимое для вложения в каждое предприятие: {list(best_investments)}")
print(f"Итоговая прибыль: {max_utility}")