import random
import math

# Функция приспособленности - значение уравнения эллипса
def fitness(x, y):
    return 6 * x - x * x + 4 * y - y * y

# Создание случайного хромосомы
def create_chromosome():
    x = random.uniform(-10, 10)  # Случайное значение переменной x
    y = random.uniform(-10, 10)  # Случайное значение переменной y
    return [x, y]

# Создание начальной популяции
def create_population(population_size):
    population = []
    for _ in range(population_size):
        chromosome = create_chromosome()
        population.append(chromosome)
    return population

# Оператор скрещивания (одноточечный)
def crossover(parent1, parent2):
    crossover_point = random.randint(0, len(parent1) - 1)
    child = parent1[:crossover_point] + parent2[crossover_point:]
    return child

# Оператор мутации
def mutate(chromosome, mutation_rate):
    for i in range(len(chromosome)):
        if random.random() < mutation_rate:
            chromosome[i] = random.uniform(-10, 10)
    return chromosome

# Генетический алгоритм
def genetic_algorithm(population_size, generations, mutation_rate):
    population = create_population(population_size)

    for _ in range(generations):
        # Оценка приспособленности
        fitness_scores = []
        for chromosome in population:
            x, y = chromosome
            fitness_score = fitness(x, y)
            fitness_scores.append((chromosome, fitness_score))

        # Сортировка по приспособленности
        fitness_scores.sort(key=lambda x: x[1], reverse=True)

        # Выбор лучших родителей
        parents = [chromosome for chromosome, _ in fitness_scores[:2]]

        # Создание новой популяции
        new_population = [parents[0], parents[1]]
        while len(new_population) < population_size:
            parent1 = random.choice(parents)
            parent2 = random.choice(parents)
            child = crossover(parent1, parent2)
            child = mutate(child, mutation_rate)
            new_population.append(child)

        population = new_population

    # Возврат наилучшего решения
    best_chromosome = max(population, key=lambda x: fitness(x[0], x[1]))
    return best_chromosome

# Параметры генетического алгоритма
population_size = 100
generations = 100
mutation_rate = 0.1

# Запуск генетического алгоритма
best_chromosome = genetic_algorithm(population_size, generations, mutation_rate)
x, y = best_chromosome
max_value = fitness(x, y)

print(f"Максимальные значения переменных: x = {x}, y = {y}")
print(f"Максимальное значение уравнения эллипса: {max_value}")