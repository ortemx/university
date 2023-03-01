'''
Digital signature
'''


class Message:
    """_summary_
    """

    text: str
    key: tuple
    signature: int

    def __init__(self, text: str, key: tuple, signature: int):
        self.text = text
        self.key = key
        self.signature = signature

    def print(self) -> None:
        """выводит информацию о сообщении
        """
        print(
            "text:", self.text,
            "\ne =", self.key[0],
            "\nn =", self.key[1],
            "\nsignature =", self.signature
        )

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

    # return 2082092083021
    # return 99
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

    e = 5
    n = 255
    d = 29
    h = get_hash_of_text(text)
    s = pow(h, d, n)
    msg = Message(text, (e, n), s)
    msg.print()

    return msg


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

    message.print()
    hash_of_text:int = get_hash_of_text(message.text)
    hash_of_key:int = pow(message.signature, message.key[0], message.key[1])

    print(hash_of_text, hash_of_key)
    return hash_of_text == hash_of_key


txt = "ты лох"
msg = genetare_message(txt)

print(validation_message(msg))
