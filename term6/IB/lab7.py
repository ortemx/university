'''
Encryption using analytical transformations
'''

from numpy import linalg as la
from numpy import matmul


def encrypt(matrix: list, text: str) -> str:
    if len(text) % 3 == 2:
        text += "*"
    elif len(text) % 3 == 1:
        text += "**"
    
    output = ""
    for i in range(len(text) // 3):
        part_of_text = text[i * 3: (i + 1) * 3]
        vec = [ord(i) for i in part_of_text]
        output += ' '.join(map(str, matmul(matrix, vec))) + " "
    
    return output[:-1]


def decrypt(matrix: list, encrypt_text: str) -> str:
    A = la.inv(matrix)
    vec = list(map(int, encrypt_text.split(" ")))
    output = ""
    for i in range(len(vec) // 3):
        part_of_vec = map(round, matmul(A, vec[i * 3: (i + 1) * 3]))
        for i in part_of_vec:
            output += chr(i)    
    return output


text = "БЛАГОВЕЩЕНИЕ"
    
A = [
    [11, 7, -4],
    [7, 4, -3],
    [2, 2, -1]
]

ENCRYPTED_STRING = encrypt(A, text)
print(f"Шифрограмма для \"{text}\":\n\t{ENCRYPTED_STRING}")

DECRYPTED_STRING = decrypt(A, ENCRYPTED_STRING)
print(f"Дешифровка для \"{ENCRYPTED_STRING}\":\n\t{DECRYPTED_STRING}")