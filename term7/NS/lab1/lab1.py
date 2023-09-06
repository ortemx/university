import numpy as np

# Функция активации сигмоида
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# Размерность входного слоя
n_input = 3

# Количество нейронов в выходном слое
n_output = 1

# Случайные веса для входного и выходного слоев
W_in = np.random.randn(n_output, n_input)
W_out = np.random.randn(1, n_output)

# Бинарная функция ошибки
def error(y_pred, y):
    diff = y_pred - y
    squared_diff = diff**2
    return sum(squared_diff) / len(squared_diff)

for i in range(1000):
    # Генерация входного массива
    x = np.array([0, 0, 1])

    # Расчет предсказаний для каждого нейрона
    y_pred = x @ W_in

    # Вычисление ошибки
    error_value = error(y_pred[0], 0)

    if error_value < 0.1:
        break

print("Ошибка на тестовом наборе:", error_value)