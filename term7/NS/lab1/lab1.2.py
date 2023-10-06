import numpy as np


def train_test_split(X, y, test_size, random_state=None):
    if random_state is not None:
        np.random.seed(random_state)

    indices = np.arange(len(X))
    np.random.shuffle(indices)

    test_samples = int(len(X) * test_size)
    test_indices = indices[:test_samples]
    train_indices = indices[test_samples:]

    X_train = X[train_indices]
    X_test = X[test_indices]
    y_train = y[train_indices]
    y_test = y[test_indices]

    return X_train, X_test, y_train, y_test


def accuracy_score(y_true, y_pred):
    correct = 0
    for t, p in zip(y_true, y_pred):
        if t == p:
            correct += 1
    return correct / len(y_true)


class Perceptron:
    def __init__(self, input_size):
        self.weights = np.random.rand(input_size)
        self.bias = np.random.rand()
    
    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))
    
    def predict(self, inputs):
        weighted_sum = np.dot(inputs, self.weights) + self.bias
        return self.sigmoid(weighted_sum)
    
    def train(self, inputs, labels, epochs):
        for _ in range(epochs):
            for x, y in zip(inputs, labels):
                predicted = self.predict(x)
                error = y - predicted
                self.weights += x * error
                self.bias += error

# Пример использования
# Загрузка и подготовка данных
data = np.genfromtxt("term7/NS/lab1/iris.data", delimiter=",", dtype=str, skip_header=51)
# print(data)
iris_features = data[:, :-1].astype(float)
iris_labels = data[:, -1]
iris_labels = np.where(iris_labels == "Iris-versicolor", 1, 0)


# Разделение данных на обучающий и тестовый наборы
X_train, X_test, y_train, y_test = train_test_split(iris_features, iris_labels, test_size=0.1, random_state=42)

# Создание и обучение персептрона
perceptron = Perceptron(input_size=X_train.shape[1])
perceptron.train(X_train, y_train, epochs=100)

# Предсказание на тестовых данных
predictions = perceptron.predict(X_test)
# print(predictions)

# Оценка точности модели
accuracy = accuracy_score(y_test, predictions)
# print("Accuracy:", accuracy)

# набор для проверки 7.0,3.2,4.7,1.4

print(perceptron.predict([7.0, 3.2, 4.7, 1.4]))