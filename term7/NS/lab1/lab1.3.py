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
nand_labels = np.array([1, 1, 1, 0])
eq_labels = np.array([1, 0, 0, 1])

nand_perceptron = Perceptron(2)
nand_perceptron.train(inputs, nand_labels, epochs=1000)

eq_perceptron = Perceptron(2)
eq_perceptron.train(inputs, eq_labels, epochs=1000)


print("NAND perceptron predictions:")
for x in inputs:
    print(x, nand_perceptron.predict(x))


print("EQUALITY perceptron predictions:")
for x in inputs:
    print(x, eq_perceptron.predict(x))