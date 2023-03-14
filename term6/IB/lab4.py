'''
Digital signature + RSA
'''


import math


class Message:
    """класс, описывающий структуру сообщения,
    состоящий их текста, открытого ключа, электронной попдписи
    """

    __text: str
    __key: tuple
    __signature: int

    def __init__(self, text: str, key: tuple, signature: int):
        self.__text = text
        self.__key = key
        self.__signature = signature

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

    
def euler(n: int) -> int:
    size = n // 2
    sieve = [1]*size
    limit = int(n**0.5)
    for i in range(1,limit):
        if sieve[i]:
            val = 2*i+1
            tmp = ((size-1) - i)//val 
            sieve[i+val::val] = [0]*tmp    
    PRIMES = [2] + [i*2+1 for i, v in enumerate(sieve) if v and i>0]
    
    original_n = n
    prime_factors = []
    prime_index = 0
    while n > 1: # As long as there are more factors to be found
        p = PRIMES[prime_index]
        if (n % p == 0): # is this prime a factor?
            prime_factors.append(p)
            while math.ceil(n / p) == math.floor(n / p): # as long as we can devide our current number by this factor and it gives back a integer remove it
                n = n // p

        prime_index += 1

    for v in prime_factors: # Now we have the prime factors, we do the same calculation as wikipedia
        original_n *= 1 - (1/v)

    return int(original_n)
    
    
def gen_public_key() -> tuple:
    """_summary_

    Returns:
        tuple: _description_
    """
    
    p: int = 0
    q: int = 0
    
    min_value: int = 1000
    while True:
        if is_prime(min_value):
            p = min_value
            min_value *= 2
            break
        else:
            min_value += 1
            

    while True:
        if is_prime(min_value):
            q = min_value
            break
        else:
            min_value += 1    
    
    n = p * q
    # fi_n: int = (p - 1) * (q - 1)
    fi_n: int = euler(n)
    
    e: int = 0
    for i in range (fi_n - 1, int(math.sqrt(fi_n)), -1):
        if math.gcd(i, fi_n) == 1:
            e = i
            break
    
    return (e, n)


def gen_private_key(public_key: tuple) -> int:
    e = public_key[0]
    n = public_key[1]
    fi_n = euler(n)
    d = (120 - 1) * e

    while True:
        if d * e % fi_n == 1:
            break
        else:
            d += 1

    return d


def get_hash_of_text(text: str, n: int) -> int:
    """высчитывает хэш код сообщения с
    помощью функции квадратичной свертки

    Args:
        text (str): входное сообщение
        n (int): модуль, по которому высчитывается значение
        функции (должен быть больше лю)
    Returns:
        int: 
    """

    hash_code: int = 0

    for letter in text:
        hash_code = pow(hash_code + ord(letter), 2, n)

    return hash_code


def genetare_message(text: str)-> Message:
    """генерирует сообщения отправителя
    для последущей отправки

    Args:
        text (str): сообщение отправителя

    Returns:
        tuple: сообщение состоит из
        текста,
        открытого ключа,
        электронной подписи
    """
    
    public_key = gen_public_key()
    private_key = gen_private_key(public_key)
    e = public_key[0]
    n = public_key[1]
    d = private_key
    h = get_hash_of_text(text, n)
    s = pow(h, d, n)

    return Message(text, public_key, s)


def validation_message(message: Message) -> bool:
    """проверяет подлиность автора сообщения

    Args:
        message (Message): сообщение, состоящее из
        текста сообщения,
        открытого ключа отправителя,
        электронной подписи

    Returns:
        bool: _description_
    """

    # message.print()
    hash_of_text:int = get_hash_of_text(message.text, message.key[1])
    hash_of_key:int = pow(message.signature, message.key[0], message.key[1])

    # print(hash_of_text, hash_of_key)
    return hash_of_text == hash_of_key


txt = ""
msg = genetare_message(txt)

print("отправитель", " не" if not validation_message(msg) else "", " подтвержден", sep="")
