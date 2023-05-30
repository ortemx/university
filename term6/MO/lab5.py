import numpy as np

capital_investments = 5
# вариант 8
utility_matrix = np.array([[0.0, 1.0, 2.3, 3.4, 3.5, 4.3],
                           [0.0, 2.0, 3.0, 4.5, 4.9, 5.1],
                           [0.0, 3.1, 3.5, 4.0, 4.6, 5.5]])
# вариант 5
# utility_matrix = np.array([[0.0, 3.2, 3.4, 4.0, 4.5, 5.3],
#                            [0.0, 3.5, 4.0, 4.6, 5.0, 5.9],
#                            [0.0, 4.3, 4.5, 5.1, 6.0, 6.8]])

# вариант 7
utility_matrix = np.array([[0.0, 2.0, 2.4, 3.0, 3.6, 4.4],
                           [0.0, 1.5, 2.0, 2.8, 4.0, 5.1],
                           [0.0, 2.3, 2.8, 3.4, 4.8, 5.6]])

num_enterprises = utility_matrix.shape[0]
optimal_utilities = np.zeros((num_enterprises, capital_investments+1))
investments_matrix = np.zeros((num_enterprises, capital_investments+1, num_enterprises))

for i in range(1, num_enterprises):
    for j in range(1, capital_investments+1):
        max_utility = 0.
        for k in range(min(j+1, len(utility_matrix[i-1]))):
            if k <= j:
                utility = utility_matrix[i-1, k] + optimal_utilities[i-1, j-k]
                if utility > max_utility:
                    max_utility = utility
                    investments_matrix[i, j] = investments_matrix[i-1, j-k].copy()
                    investments_matrix[i, j, i-1] = k
            else:
                break
        optimal_utilities[i, j] = max_utility

investments = investments_matrix[num_enterprises-1, capital_investments].astype(int).tolist()
total_utility = optimal_utilities[num_enterprises-1, capital_investments]

print(f"Количество капитала, необходимое для вложения в каждое предприятие: {investments}")
print(f"Итоговая прибыль: {total_utility}")