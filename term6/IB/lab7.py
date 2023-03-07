"""_

ОННА -НЦОН- -ДЛЬХ- -ФИСН- ИАТЫ КЕЬД

612453
конфид
енциал
ьность
данныx

"""


def matr_by_vec(A, b):
    b0 = A[0][0] * b[0] + A[0][1] * b[1] + A[0][2] * b[2]
    b1 = A[1][0] * b[0] + A[1][1] * b[1] + A[1][2] * b[2]
    b2 = A[2][0] * b[0] + A[2][1] * b[1] + A[2][2] * b[2]
    
    return [round(b0), round(b1), round(b2)]


str = "БЛАГОВЕЩЕНИЕ"
    
A = [
    [11, 7, -4],
    [7, 4, -3],
    [2, 2, -1]
]

A_inv = [
    [2 / 5,	-1 / 5,	-1],
    [1 / 5,	-3 / 5,	 1],
    [6 / 5,	-8 / 5,	-1]
]

mes = []
for i in range(len(str) // 3):
    temp = str[i * 3: (i+1) * 3]
    vec = [i for i in temp.encode('cp1251')]
    print(vec)
    mes.append(matr_by_vec(A, vec))
    # print(matr_by_vec(A, vec))

# print(mes)

for i in mes:
    print(matr_by_vec(A_inv, i))