from sklearn.datasets import fetch_20newsgroups
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import classification_report

# Загрузка данных из корпуса "20 Newsgroups"
newsgroups = fetch_20newsgroups(subset='all')

# Преобразование текстовых данных в числовой формат
vectorizer = TfidfVectorizer()
X = vectorizer.fit_transform(newsgroups.data)

# Разделение данных на обучающую и тестовую выборки
X_train, X_test, y_train, y_test = train_test_split(X, newsgroups.target, test_size=0.3, random_state=42)

# Обучение SVM
clf = SVC(kernel='linear', C=1, gamma='auto')
clf.fit(X_train, y_train)

# Оценка качества модели на тестовой выборке
y_pred = clf.predict(X_test)
print(classification_report(y_test, y_pred, target_names=newsgroups.target_names))
