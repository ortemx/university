from itertools import combinations

products = {
    'пицца'     : 85,
    'хлеб'      : 35,
    'лапша'     : 13,
    'молоко'    : 65,
    'батончк'   : 55,
    'шаверма'   : 170
}

cash: int = 100

print("если у студента ", cash, "рублей, то он сможет купить: ")
for i in range(1, 7):
    comb = list(combinations(products, i))
    for j in comb:
        purchaseAmount = 0
        for k in j:
            purchaseAmount += products[k]
        change = cash - purchaseAmount
        if change > 0:
            for k in j:
                print(k, end=" ")
            print(", тогда сдача =", change, "рублей")