"""

"""

from itertools import permutations as pt


def get_possible_keys(known_key: str) -> list:
    """генерирует всевозможные ключи по 
    восстановленной части

    Args:
        known_key (_type_): _description_
    """

    # находим неизвестные значения в ключе
    unknown_numbers = [i[0] + 1 for i in enumerate(known_key)]
    for i in known_key:
        if i.isnumeric():
            unknown_numbers.remove(int(i))

    # массив, в котором будут храниться всевозможные вырианты
    possible_keys  = []
    # генерация перестановок неизвестной части ключа
    prmtns = pt(unknown_numbers)

    for prmtn in prmtns:
        possible_key = [0] * len(known_key)
        i = 0
        for j, value in enumerate(known_key):
            if value.isnumeric():
                possible_key[j] = int(value)
            else:
                possible_key[j] = prmtn[i]
                i += 1
        possible_keys.append(possible_key)
    return possible_keys


def generate_decrypt(keys, encrypt_str):
    """генерация всех перестановок входного слова по ключам

    Args:
        keys (_type_): ключи-перестановки
        encrypt_str (_type_): строка
    """
    for key in keys:
        decrypt = [""] * len(encrypt_str)
        for j, k in enumerate(key):
            len_part = len(encrypt_str) // len(key)
            part = encrypt_str[(k - 1) * len_part: k * len_part]
            for k, letter in enumerate(part):
                decrypt[j + k * len(key)] = letter
        key = ''.join(map(str, key))
        decrypt = ''.join(decrypt)
        print(f"key = {key}, decrypt = {decrypt}")

encrypt = {
    "key": "xx24x3",
    "text": "ОННАНЦОНДЛЬХФИСНИАТЫКЕЬД"
}

generate_decrypt(get_possible_keys(encrypt["key"]), encrypt["text"])
