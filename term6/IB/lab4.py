'''
Digital signature
'''


def get_hash_of_text(text: str) -> int:
    """возвращает хэш код сообщения с
    помощью функции квадратичной свертки

    Args:
        text (str): входное сообщение

    Returns:
        int:
    """

    hash_code: int = 0

    for letter in text.encode("utf-8"):
        hash_code = pow(hash_code + letter, 2, 255)
        # print(hash_code, letter)

    return hash_code


def genetare_message(text: str)-> tuple:
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

    e = 5
    n = 91
    d = 29
    h = get_hash_of_text(text)
    s = pow(h, d) % n

    return (text, (e, n), s)


def validation_message(message: tuple) -> bool:
    """проверяет подлиность автора сообщения

    Args:
        message (tuple): сообщение, состоящее из
        текста сообщения,
        открытого ключа отправителя,
        электронной подписи

    Returns:
        bool: _description_
    """

    hash_of_text:int = get_hash_of_text(message[0])
    hash_of_key:int = pow(message[2], message[1][0], message[1][1])

    return hash_of_text == hash_of_key


txt = "ты лох"
msg = genetare_message(txt)

print(validation_message(msg))
