import numpy as np

# Задаем таблицу тарифов
costs = np.array([[30, 2, 5, 6, 15], [5, 29, 9, 5, 7], [
                 16, 24, 14, 6, 26], [13, 28, 4, 25, 8]])

# Задаем запасы и потребности
supplies = np.array([16, 15, 14, 15])
demands = np.array([6, 6, 13, 20, 15])


def northwestangle(costs, supplies, demands):
    # Создаем матрицу распределения ресурсов
    allocation = np.zeros((len(supplies), len(demands)))

    # Проверяем, сбалансирована ли задача
    if np.sum(supplies) != np.sum(demands):
        # Добавляем дополнительную поставку или потребность
        if np.sum(supplies) < np.sum(demands):
            supplies = np.append(supplies, np.sum(demands) - np.sum(supplies))
            costs = np.vstack((costs, np.zeros((1, costs.shape[1]))))
        elif np.sum(supplies) > np.sum(demands):
            demands = np.append(demands, np.sum(supplies) - np.sum(demands))
            costs = np.hstack((costs, np.zeros((costs.shape[0], 1))))

    # Создаем матрицу распределения ресурсов
    allocation = np.zeros((len(supplies), len(demands)))

    # Инициализируем индексы строк и столбцов
    row_ind = 0
    col_ind = 0

    # Заполняем матрицу распределения ресурсов, начиная с левого верхнего угла
    while row_ind < allocation.shape[0] and col_ind < allocation.shape[1]:
        if supplies[row_ind] < demands[col_ind]:
            allocation[row_ind, col_ind] = supplies[row_ind]
            demands[col_ind] -= supplies[row_ind]
            row_ind += 1
        else:
            allocation[row_ind, col_ind] = demands[col_ind]
            supplies[row_ind] -= demands[col_ind]
            col_ind += 1

    # Выводим матрицу распределения ресурсов и общую стоимость
    print("Optimal allocation:")
    print(allocation)
    print(f"Total cost: {np.sum(costs * allocation)}")


# northwestangle(costs, supplies, demands)

grid = [[30, 2, 5, 6, 15], [5, 29, 9, 5, 7], [
    16, 24, 14, 6, 26], [13, 28, 4, 25, 8]]  # table
supply = [16, 15, 14, 15]  # supply
demand = [6, 6, 13, 20, 15]  # demand
INF = 10**3
n = len(grid)
m = len(grid[0])
ans = 0

# hepler function for finding the row difference and the column difference


def findDiff(grid):
    rowDiff = []
    colDiff = []
    for i in range(len(grid)):
        arr = grid[i][:]
        arr.sort()
        rowDiff.append(arr[1]-arr[0])
    col = 0
    while col < len(grid[0]):
        arr = []
        for i in range(len(grid)):
            arr.append(grid[i][col])
        arr.sort()
        col += 1
        colDiff.append(arr[1]-arr[0])
    return rowDiff, colDiff


# loop runs until both the demand and the supply is exhausted
while max(supply) != 0 or max(demand) != 0:
    # finding the row and col difference
    row, col = findDiff(grid)
    # finding the maxiumum element in row difference array
    maxi1 = max(row)
    # finding the maxiumum element in col difference array
    maxi2 = max(col)

    # if the row diff max element is greater than or equal to col diff max element
    if (maxi1 >= maxi2):
        for ind, val in enumerate(row):
            if (val == maxi1):
                # finding the minimum element in grid index where the maximum was found in the row difference
                mini1 = min(grid[ind])
                for ind2, val2 in enumerate(grid[ind]):
                    if (val2 == mini1):
                        # calculating the min of supply and demand in that row and col
                        mini2 = min(supply[ind], demand[ind2])
                        ans += mini2 * mini1
                        # subtracting the min from the supply and demand
                        supply[ind] -= mini2
                        demand[ind2] -= mini2
                        # if demand is smaller then the entire col is assigned max value so that the col is eliminated for the next iteration
                        if (demand[ind2] == 0):
                            for r in range(n):
                                grid[r][ind2] = INF
                        # if supply is smaller then the entire row is assigned max value so that the row is eliminated for the next iteration
                        else:
                            grid[ind] = [INF for i in range(m)]
                        break
                break
    # if the row diff max element is greater than col diff max element
    else:
        for ind, val in enumerate(col):
            if (val == maxi2):
                # finding the minimum element in grid index where the maximum was found in the col difference
                mini1 = INF
                for j in range(n):
                    mini1 = min(mini1, grid[j][ind])

                for ind2 in range(n):
                    val2 = grid[ind2][ind]
                    if val2 == mini1:
                        # calculating the min of supply and demand in that row and col
                        mini2 = min(supply[ind2], demand[ind])
                        ans += mini2 * mini1
                        # subtracting the min from the supply and demand
                        supply[ind2] -= mini2
                        demand[ind] -= mini2
                        # if demand is smaller then the entire col is assigned max value so that the col is eliminated for the next iteration
                        if (demand[ind] == 0):
                            for r in range(n):
                                grid[r][ind] = INF
                        # if supply is smaller then the entire row is assigned max value so that the row is eliminated for the next iteration
                        else:
                            grid[ind2] = [INF for i in range(m)]
                        break
                break
    
print(grid)
print("The basic feasible solution is ", ans)
