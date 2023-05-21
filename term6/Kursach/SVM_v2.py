import pickle
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score
from sklearn.metrics import classification_report
from sklearn.preprocessing import StandardScaler


# Загрузка набора данных MNIST
digits = datasets.load_digits()

# Нормализация данных
scaler = StandardScaler()
X_scaled = scaler.fit_transform(digits.data)

# Разделение набора данных на обучающую и тестовую выборки
X_train, X_test, y_train, y_test = train_test_split(digits.data, digits.target, test_size=0.3, random_state=42)

# Обучение SVM на обучающей выборке
clf = SVC(kernel='linear', C=1, gamma='auto')
clf.fit(X_train, y_train)

# Предсказание меток классов на тестовой выборке
y_pred = clf.predict(X_test)

# Оценка качества модели с помощью метрики accuracy
print("Accuracy:", accuracy_score(y_test, y_pred))

# Вывод отчета о классификации
print(classification_report(y_test, y_pred))

# Сохранение модели в файл
with open('D:/GH/university/term6/Kursach/svm_model.pkl', 'wb') as f:
    pickle.dump(clf, f)
