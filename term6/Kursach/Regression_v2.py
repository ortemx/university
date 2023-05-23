# import pandas as pd

# from sklearn.linear_model import LinearRegression
# from sklearn.model_selection import train_test_split

# # Загрузка данных
# data = pd.read_csv('D:/GH/university/term6/Kursach/crime.csv')

# # Извлечение признаков и целевой переменной
# X = data.drop('Total', axis=1)
# y = data['Total']

# # Разбиение на обучающую и тестовую выборки
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# # Обучение модели
# model = LinearRegression()
# model.fit(X_train, y_train)

# # Оценка качества модели на тестовой выборке
# score = model.score(X_test, y_test)
# print('R^2 score:', score)

import pandas as pd

# Загрузка данных
data = pd.read_csv('https://archive.ics.uci.edu/ml/machine-learning-databases/adult/adult.data',
                   header=None,
                   names=['age', 'workclass', 'fnlwgt', 'education', 'education_num', 'marital_status',
                          'occupation', 'relationship', 'race', 'sex', 'capital_gain', 'capital_loss',
                          'hours_per_week', 'native_country', 'income'])

# Сохранение данных в файл
data.to_csv('D:/GH/university/term6/Kursach/adult.csv', index=False)