import itertools


def tsp_brute_force(routes):
    num_cities = len(routes)
    cities = list(range(num_cities))
    min_cost = float('inf')
    min_path = None
    for path in itertools.permutations(cities):
        cost = 0
        for i in range(num_cities-1):
            cost += routes[path[i]][path[i+1]]
        cost += routes[path[-1]][path[0]]
        if cost < min_cost:
            min_cost = cost
            min_path = path
    return min_path, min_cost



inf = float('inf')

routes = [
    [inf,  56,  48,	 39,   3,  40],
    [47,  inf,  50,   4,  10,  49],
    [48,   50, inf,  42,  19,  16],
    [24,   44,  47,	inf,  23,  33],
    [38,   17,   6,  51, inf,  26],
    [29,   59,  55,	 34,  18, inf]
]


min_path, min_cost = tsp_brute_force(routes)
print("Minimum cost:", min_cost)
print("Minimum path:", tuple(city+1 for city in min_path))
