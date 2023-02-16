"""
Route cipher
"""

def print_table(table, row_num, col_num):
    '''
    вывод таблицы в удобном виде
    '''

    print("  ", end='')
    for i in range(col_num):
        print("| ", i + 1, " ", sep="", end="")
    print()

    for i in range(row_num):
        print(i+1, end='')
        for j in range(col_num):
            print(" |", table[i][j], end="")
        print()


def read_table(table, row_num, col_num, mod: str):
    """
    чтение букв из таблицы заданным маршрутом
    """

    output_str = ""
    if mod == "lr-tb":
        for i in range(row_num):
            for j in range(col_num):
                output_str += table[i][j]
    elif mod == "lr-bt":
        for i in range(row_num, 0, -1):
            for j in range(col_num):
                output_str += table[i - 1][j]
    elif mod == "rl-tb":
        for i in range(row_num):
            for j in range(col_num, 0, -1):
                output_str += table[i][j - 1]
    elif mod == "rl-bt":
        for i in range(row_num, 0, -1):
            for j in range(col_num, 0, -1):
                output_str += table[i - 1][j - 1]
    elif mod == "tb-lr":
        for j in range(col_num):
            for i in range(row_num):
                output_str += table[i][j]
    elif mod == "tb-rl":
        for j in range(col_num, 0, -1):
            for i in range(row_num):
                output_str += table[i][j - 1]
    elif mod == "bt-lr":
        for j in range(col_num):
            for i in range(row_num, 0, -1):
                output_str += table[i - 1][j]
    elif mod == "bt-rl":
        for j in range(col_num, 0, -1):
            for i in range(row_num, 0, -1):
                output_str += table[i - 1][j - 1]
    else:
        print("маршрут передан неверно")
        return None

    return output_str


def encrypt(input_str: str, row_num, col_num, mod: str):
    """
    шифрование входной строки
    """

    if row_num * col_num < len(input_str):
        print("входное слово не помещается в таблицу с данными размерами")
        return

    # инициализация таблицы
    table = []

    str_index = 0

    for i in range(row_num):
        table.append([])
        for j in range(col_num):
            if str_index < len(input_str):
                table[i].append(input_str[str_index])
            else:
                table[i].append("_")
            str_index += 1

    print_table(table, row_num, col_num)
    return read_table(table, row_num, col_num, mod)


def decrypt(encrypted_str: str, row_num, col_num, mod: str):
    """
    расшифровка входной(зашифрованной) строки
    """

    if row_num * col_num != len(encrypted_str):
        print("количество букв слова должно быть рафно числу ячеек таблицы")
        return

    # инициализация таблицы
    table = []

    str_index = 0

    if mod in ["lr-tb", "lr-bt", "rl-tb", "rl-bt"]:
        for i in range(row_num):
            table.append([])
            for j in range(col_num):
                table[i].append(encrypted_str[str_index])
                str_index += 1
    elif mod in ["tb-lr", "tb-rl", "bt-lr", "bt-rl"]:
        for i in range(row_num):
            table.append([])
            for j in range(col_num):
                table[i].append("_")

        for j in range(col_num):
            for i in range(row_num):
                table[i][j] = encrypted_str[str_index]
                str_index += 1

    print_table(table, row_num, col_num)

    decrypted_str = ""
    if mod in ["lr-tb", "lr-bt", "rl-tb", "rl-bt"]:
        decrypted_str = read_table(table, row_num, col_num, mod)
    elif mod == "tb-lr":
        decrypted_str = read_table(table, row_num, col_num, "lr-tb")
    elif mod == "tb-rl":
        decrypted_str = read_table(table, row_num, col_num, "rl-tb")
    elif mod == "bt-lr":
        decrypted_str = read_table(table, row_num, col_num, "lr-bt")
    elif mod == "bt-rl":
        decrypted_str = read_table(table, row_num, col_num, "rl-bt")
    else:
        print("не верно передан маршрут считывания")
        return
    return decrypted_str


string: str = "Конышев_Артём_Евгеньевич_302_1"
# string = "Шифр_табличной_маршрутной_перестановки"
print("Входное слово:", string)

routes = {
    0: "lr-tb",
    1: "lr-bt",
    2: "rl-tb",
    3: "rl-bt",
    4: "tb-lr",
    5: "tb-rl",
    6: "bt-lr",
    7: "bt-rl"
}

encrypted_string = encrypt(string, 5, 9, routes[7])
print("Зашифрованное слово:", encrypted_string)
print("Расшифрованное слово:", decrypt(encrypted_string, 5, 9, routes[7]))
