"""
lab_2 on IB
"""
import random as r


def print_table(table, row_num, col_num):
    """
    print cipher-table
    """
    print("  ", end='')
    for i in range(col_num):
        print("| ", i + 1, " ", sep="", end="")
    print()

    for i in range(row_num):
        print(i+1, end='')
        for j in range(col_num):
            print(" |", table[i][j], end="")
        print()


INPUT_STR: str = "Конышев_Артем_Евгеньевич_302_1".upper()

print("input:", INPUT_STR)

alphabet: str = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ_0123456789"
l = list(alphabet)
r.shuffle(l)
ALPHABET = ''.join(l)

count:int = 0

ROW_COUNT:int = 6
COL_COUNT:int = 8
table = []


for i in range(ROW_COUNT):
    table.append([])
    for j in range(COL_COUNT):
        if count >= len(ALPHABET):
            table[i].append("\u00A0")
        else:
            table[i].append(ALPHABET[count])
        count += 1

print_table(table, ROW_COUNT, COL_COUNT)

ouput_str: str = ''
for letter in INPUT_STR:
    for i in range(ROW_COUNT):
        for j in range(COL_COUNT):
            if letter == table[i][j]:
                # print(i + 1, j + 1, sep='', end='')
                ouput_str += str(i + 1) + str(j + 1)
    # print(end=' ')
    ouput_str += "_"

print("output:", ouput_str)
