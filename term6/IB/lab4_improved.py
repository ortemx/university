'''
Digital signature + RSA
'''


import math
from random import randint
from random import choices

class Message:
    """класс, описывающий структуру сообщения,
    состоящий их текста, открытого ключа, электронной попдписи
    """

    __text: str
    __key: tuple
    __signature: int

    def __init__(self, text: str):
        public_key = gen_public_key()
        private_key = gen_private_key(public_key)
        n = public_key[1]
        d = private_key
        h = get_hash_of_text(text, n)

        self.__text = text
        self.__key = public_key
        self.__signature = pow(h, d, n)

    @property
    def text(self):
        """текст сообщения
        """
        return self.__text

    @property
    def key(self):
        """Открытый ключ, состоящий из 2 частей:
        открытой экспоненты и модуля
        """
        return self.__key

    @property
    def signature(self):
        return self.__signature

    def print(self) -> None:
        """выводит информацию о сообщении
        """
        print(
            "text:", self.__text,
            "\ne =", self.__key[0],
            "\nn =", self.__key[1],
            "\nsignature =", self.__signature
        )


def is_prime(num: int) -> bool:
    if num < 2:
        return False
    sqr = int(math.sqrt(num))
    for i in range(2, sqr + 1):
        if num % i == 0:
            return False
    return True


def gen_public_key() -> tuple:
    """функция генерации открытого ключа

    Returns:
        tuple: e, n, значении функции Эйлера в n
    """

    p: int = 0
    q: int = 0

    min_p: int = randint(10000, 20000)
    while True:
        if is_prime(min_p):
            p = min_p
            min_p *= 2
            break
        else:
            min_p += 1

    min_q: int = randint(20000, 30000)
    while True:
        if is_prime(min_q):
            q = min_q
            break
        else:
            min_q += 1

    n = p * q
    fi_n: int = (p - 1) * (q - 1)

    e: int = 0
    for i in range (fi_n - 1, int(math.sqrt(fi_n)), -1):
        if math.gcd(i, fi_n) == 1:
            e = i
            break

    return (e, n, fi_n)


def gen_private_key(public_key: tuple) -> int:
    """Генерирует закрытый ключ

    Args:
        public_key (tuple): открытый ключ
    """
    e = public_key[0]
    fi_n = public_key[2]

    set_of_d = []
    d = 199 * e

    while len(set_of_d) < 20:
        if d * e % fi_n == 1:
            set_of_d.append(d)
            d += e
        d += 1

    return choices(set_of_d)


def get_hash_of_text(text: str, n: int) -> int:
    """высчитывает хэш код сообщения с
    помощью функции квадратичной свертки

    Args:
        text (str): входное сообщение
        n (int): модуль, по которому высчитывается значение
        функции (должен быть больше кода любого символа алфаваита)
    """

    hash_code: int = 0

    for letter in text:
        hash_code = pow(hash_code + ord(letter), 2, n)

    return hash_code


def validation_message(message: Message) -> bool:
    """проверяет подлиность автора сообщения

    Args:
        message (Message): сообщение, состоящее из
        текста сообщения,
        открытого ключа отправителя,
        электронной подписи

    Returns:
        bool: True, если отправитель подтвержден, False иначе
    """

    # message.print()
    hash_of_text:int = get_hash_of_text(message.text, message.key[1])
    hash_of_key:int = pow(message.signature, message.key[0], message.key[1])

    # print(hash_of_text, hash_of_key)
    return hash_of_text == hash_of_key


TXT = "azbuka"
msg = Message(TXT)

print("отправитель подтвержден" if validation_message(msg) else "отправитель не подтвержден")
