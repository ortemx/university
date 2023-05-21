from sklearn.datasets import fetch_20newsgroups
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import classification_report

# Загружаем данные (категории новостей) из библиотеки Scikit-learn
newsgroups_train = fetch_20newsgroups(subset='train')
newsgroups_test = fetch_20newsgroups(subset='test')

# Преобразуем текст в числовые признаки с помощью векторизатора CountVectorizer
vectorizer = CountVectorizer()
X_train = vectorizer.fit_transform(newsgroups_train.data)
X_test = vectorizer.transform(newsgroups_test.data)

# Создаем классификатор на основе наивного байесовского алгоритма
clf = MultinomialNB()

# Обучаем классификатор на обучающей выборке
clf.fit(X_train, newsgroups_train.target)

# Предсказываем метки классов для тестовой выборки
y_pred = clf.predict(X_test)

# Выводим отчет о классификации, включая точность, полноту и F-меру
print(classification_report(
    newsgroups_test.target,
    y_pred,
    target_names=newsgroups_test.target_names
))
