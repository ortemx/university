import numpy as np
from sklearn.linear_model import LinearRegression

# Генерация данных для 1000 домов
np.random.seed(0)
size = np.round(np.random.uniform(30, 120, 1000))
bedrooms = np.round(np.random.uniform(1, 4, 1000))
distances = np.arange(0, 15.5, 0.5)
distances = np.tile(distances, 33)[:1000]
prices = 1000000 + (size * 20000) + (bedrooms * 45000) - (distances * 100000) + np.random.normal(0, 500000, 1000)


# Создание экземпляра модели линейной регрессии и обучение ее на сгенерированных данных
model = LinearRegression()
model.fit(np.column_stack((size, bedrooms, distances)), prices)


# Вывод предсказанной цены на экран
print("размер | комнаты | от центра | цена")
data = np.array([[32, 1, 0]])
print(f"{data[0][0]:6d} | {data[0][1]:7d} | {data[0][2]:8.1f} | {model.predict(data)[0]:.2f}")
data = np.array([[45, 2, 0]])
print(f"{data[0][0]:6d} | {data[0][1]:7d} | {data[0][2]:8.1f} | {model.predict(data)[0]:.2f}")
data = np.array([[64, 3, 0]])
print(f"{data[0][0]:6d} | {data[0][1]:7d} | {data[0][2]:8.1f} | {model.predict(data)[0]:.2f}")
data = np.array([[80, 4, 0]])
print(f"{data[0][0]:6d} | {data[0][1]:7d} | {data[0][2]:8.1f} | {model.predict(data)[0]:.2f}")
data = [[80, 4, 2.5]]
print(f"{data[0][0]:6d} | {data[0][1]:7d} | {data[0][2]:8.1f} | {model.predict(data)[0]:.2f}")
data = np.array([[80, 4, 5]])
print(f"{data[0][0]:6d} | {data[0][1]:7d} | {data[0][2]:8.1f} | {model.predict(data)[0]:.2f}")
data = np.array([[45, 3, 5]])
print(f"{data[0][0]:6d} | {data[0][1]:7d} | {data[0][2]:8.1f} | {model.predict(data)[0]:.2f}")
data = np.array([[34, 2, 6]])
print(f"{data[0][0]:6d} | {data[0][1]:7d} | {data[0][2]:8.1f} | {model.predict(data)[0]:.2f}")

print(model.coef_)
print("Пересечение: ", model.intercept_)