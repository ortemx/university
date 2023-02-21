"""
lab_2 on IB 'Polybius square'
"""
import random


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


def make_cipher_table(row_num, col_num):
    """
    создает и заполняет таблицу символами алфавита
    """
    alphabet = list("АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ_0123456789")
    random.shuffle(alphabet)
    symbols = ''.join(alphabet)

    if row_num * col_num < len(symbols):
        print("Размеры таблицы малы, кол-во ячеек должно быть >= ", len(symbols))
        return

    str_index: int = 0

    table = []

    for i in range(row_num):
        table.append([])
        for j in range(col_num):
            if str_index < len(symbols):
                table[i].append(symbols[str_index])
            else:
                # "\u00A0" - nbsp
                table[i].append("\u00A0")
            str_index += 1

    return table


def encrypt(table, input_str: str):
    """
    зашифровка
    """

    row_num = len(table)
    col_num = len(table[0])

    print_table(table, row_num, col_num)

    encrypted_word: str = ''
    for letter in input_str:
        for i in range(row_num):
            for j in range(col_num):
                if letter == table[i][j]:
                    encrypted_word += str(i + 1) + str(j + 1)
        encrypted_word += "_"

    return encrypted_word[:-1]


def decrypt(table, encrypted_str: str):
    """
    расшифровка входной(зашифрованной) строки
    """

    indexes_of_symbols = encrypted_str.split("_")

    row_num = len(table)
    col_num = len(table[0])

    decrypted_str = ""
    for letter in indexes_of_symbols:
        for i in range(row_num):
            for j in range(col_num):
                if i == int(letter[0]) - 1 and j == int(letter[1]) - 1:
                    decrypted_str += table[i][j]

    return decrypted_str


# INPUT_STR: str = "Конышев_Артем_Евгеньевич_302_1".upper()
INPUT_STR: str = "Шифр_табличной_маршрутной_перестановки".upper()
print("ВХОДНОЕ СЛОВО: ", INPUT_STR)

cipher_table = make_cipher_table(5, 9)

ENCRYPTED_STRING = encrypt(cipher_table, INPUT_STR)
print("ШИФРОГРАММА:", ENCRYPTED_STRING)

DECRYPTED_STRING = decrypt(cipher_table, ENCRYPTED_STRING)
print("РАСШИФРОВАННОЕ СЛОВО:", DECRYPTED_STRING)
