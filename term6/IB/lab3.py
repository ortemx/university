"""
Gamma generator
"""

def get_register(input_str: str) -> list:
    """
    Возвращает регистр для входной строки
    """

    register: list = [0, 0, 0, 0, 0, 0, 0, 0]

    for letter in input_str:
        bin_value = '{0:0>8b}'.format(ord(letter.encode('1251')))
        for i, value in enumerate(bin_value):
            register[i] ^= int(value)
        # print(register)

    return register


def get_gamma(register: list, iter_count :int = 0) -> str:
    """
    Получение гаммы регистра до определенного числа итераций
    """

    start_reg: list = register
    reg: list = start_reg

    gamma: str = ""
    iter_num: int = 0

    while iter_num <= iter_count:
        b_0 = reg[7]
        b_7 = reg[3] ^ reg[4] ^ reg[5] ^ reg[7]

        gamma += str(b_0)

        print("iter_num = ", iter_num, "; reg =", sep="", end=" ")
        for i in reg:
            print(i, end = "")
        print()

        iter_num += 1
        reg = [b_7] + reg[0: 7]
        if reg == start_reg:
            break

    return gamma


INPUT_STR = "Конышев_Артем_Евгеньевич_триста_вторая_группа_первая_подгруппа"
print("gamma: ", get_gamma(get_register(INPUT_STR), 10))
