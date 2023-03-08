n: int = int(input('введите количество элементов: '))
k: int = int(input('введите количество элементов в наборе: '))
a = [i for i in range(k+1)]
j = k
while j != 0:
    print(a[1:k+1:1])
    j = k
    while a[j] == n-k+j:
        j -= 1
    a[j] += 1
    for i in range(j+1, k+1):
        a[i] = a[i-1] + 1
