from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score


def naive_bayesian_classifier(X_train, y_train, X_test, y_test):
    # Создаем векторизатор
    vectorizer = CountVectorizer()
    # Преобразуем текст в числовые признаки    
    X_train_vec = vectorizer.fit_transform(X_train)
    # Преобразуем текст тестовой выборки в числовые признаки
    X_test_vec = vectorizer.transform(X_test)
    # Создаем классификатор на основе наивного байесовского алгоритма
    clf = MultinomialNB()
    # Обучаем классификатор на обучающей выборке
    clf.fit(X_train_vec, y_train)
    # Предсказываем метки классов для тестовой выборки
    y_pred = clf.predict(X_test_vec)
    
    return (y_pred, accuracy_score(y_test, y_pred))


# Создаем обучающую выборку
X_train = ["This is a good movie",
           "This is a bad movie",
           "This movie is not good",
           "This movie is good",
           "This movie is very bad"]

# Задаем метки классов для обучающей выборки
y_train = ["positive", "negative", "negative", "positive", "negative"]

# Создаем тестовую выборку
X_test = ["This is a very good movie",
          "This is a very bad movie"]

# Вычисляем точность классификации
y_test = ['positive', 'negative']
output = naive_bayesian_classifier(X_train, y_train, X_test, y_test)
print(
    'Ожидаемые данные:',
    y_test,
    '\nРезультаты классификации:',
    output[0],
    '\nТочность классификации:',
    output[1]
)
