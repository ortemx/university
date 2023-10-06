import numpy as np

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

# Логические вентили AND, OR, XOR
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
and_labels = np.array([0, 0, 0, 1])
or_labels = np.array([0, 1, 1, 1])
xor_labels = np.array([0, 1, 1, 0])

and_perceptron = Perceptron(2)
and_perceptron.train(inputs, and_labels, epochs=10000)

or_perceptron = Perceptron(2)
or_perceptron.train(inputs, or_labels, epochs=10000)

xor_perceptron = Perceptron(2)
xor_perceptron.train(inputs, xor_labels, epochs=10000)

print("AND perceptron predictions:")
for x in inputs:
    print(x, and_perceptron.predict(x))

print("OR perceptron predictions:")
for x in inputs:
    print(x, or_perceptron.predict(x))

print("XOR perceptron predictions:")
for x in inputs:
    print(x, xor_perceptron.predict(x))


# print(and_perceptron.weights)
# print(or_perceptron.weights)
# print(xor_perceptron.weights)
