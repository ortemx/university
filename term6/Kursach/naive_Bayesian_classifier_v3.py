import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score, confusion_matrix

# Загружаем данные (сообщения) из CSV-файла
data = pd.read_csv('D:/GH/university/term6/Kursach/spam.csv', encoding='latin-1')

# Разделяем данные на обучающую и тестовую выборки
X_train = data.v2[:4400].values
X_test = data.v2[4400:].values
y_train = data.v1[:4400].values
y_test = data.v1[4400:].values

# Преобразуем текст в числовые признаки с помощью векторизатора CountVectorizer
vectorizer = CountVectorizer()
X_train_vec = vectorizer.fit_transform(X_train)
X_test_vec = vectorizer.transform(X_test)

# Создаем классификатор на основе наивного байесовского алгоритма
clf = MultinomialNB()

# Обучаем классификатор на обучающей выборке
clf.fit(X_train_vec, y_train)

# Предсказываем метки классов для тестовой выборки
y_pred = clf.predict(X_test_vec)

# Выводим матрицу ошибок и точность классификации
print("Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("Accuracy:", accuracy_score(y_test, y_pred))