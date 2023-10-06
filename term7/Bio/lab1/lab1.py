import random


# Функция, которую мы оптимизируем (можно заменить на другую функцию)
def fitness_function(x, y):
    return x ** 2 + 2 * y ** 2


# Создаем начальную популяцию
def initialize_population(population_size, x_range, y_range):
    population = []
    for _ in range(population_size):
        x = random.uniform(*x_range)
        y = random.uniform(*y_range)
        population.append((x, y))
    return population


# Выбираем особей для скрещивания (родителей)
def select_parents(population, num_parents):
    parents = random.sample(population, num_parents)
    return parents


# Скрещивание (кроссинговер)
def crossover(parents):
    parent1, parent2 = parents
    x1, y1 = parent1
    x2, y2 = parent2

    # Простой одноточечный кроссинговер
    crossover_point = random.uniform(0, 1)
    child_x = crossover_point * x1 + (1 - crossover_point) * x2
    child_y = crossover_point * y1 + (1 - crossover_point) * y2

    return (child_x, child_y)


# Мутация
def mutate(child, mutation_rate, x_range, y_range):
    x, y = child

    # Мутация может быть случайным изменением значения переменных
    if random.random() < mutation_rate:
        x = random.uniform(*x_range)
    if random.random() < mutation_rate:
        y = random.uniform(*y_range)

    return (x, y)


# Основной цикл генетического алгоритма
def genetic_algorithm(population_size, x_range, y_range, generations, mutation_rate):
    population = initialize_population(population_size, x_range, y_range)

    for generation in range(generations):
        parents = select_parents(population, 2)
        child = crossover(parents)
        child = mutate(child, mutation_rate, x_range, y_range)

        # Оценка приспособленности для родителей и потомка
        parent_fitness = [fitness_function(x, y) for x, y in parents]
        child_fitness = fitness_function(*child)

        # Если потомок более приспособлен, заменяем худшего родителя
        if child_fitness > min(parent_fitness):
            index_to_replace = parent_fitness.index(min(parent_fitness))
            population[index_to_replace] = child

        best_individual = max(population, key=lambda ind: fitness_function(*ind))
        print(
            f"Поколение {generation}: Лучший индивид - {best_individual}, Приспособленность - {fitness_function(*best_individual)}")



population_size = 50
x_range = (-10, 10)  # Диапазон переменной x
y_range = (-10, 10)  # Диапазон переменной y
generations = 100
mutation_rate = 0.1  # Вероятность мутации

genetic_algorithm(population_size, x_range, y_range, generations, mutation_rate)