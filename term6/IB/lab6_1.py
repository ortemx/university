'''
ladder cypher
'''


def encode_ladder(msg, columns):
    # Инициализируем список списков, чтобы создать "лесенку"
    ladder = [[] for i in range(columns)]
    # Записываем сообщение в лесенку
    row = 0
    direction = 1
    for letter in msg:
        ladder[row].append(letter)
        if row == 0:
            direction = 1
        elif row == columns-1:
            direction = -1
        row += direction
    # Соединяем буквы из каждой колонки в закодированное сообщение
    encoded_message = ''
    for row in ladder:
        encoded_message += ''.join(row)
    return encoded_message


def decode_ladder(encoded_msg, columns):
    # Инициализируем список списков для создания лесенки
    ladder = [[] for i in range(columns)]
    # Вычисляем размеры колонок в лесенке
    column_lengths = []
    q, r = divmod(len(encoded_msg), columns)
    for i in range(columns):
        if i < r:
            column_lengths.append(q+1)
        else:
            column_lengths.append(q)
    # Записываем закодированное сообщение в лесенку
    row = 0
    direction = 1
    index = 0
    for length in column_lengths:
        column_letters = encoded_msg[index:index+length]
        index += length
        ladder[row] = list(column_letters)
        if row == 0:
            direction = 1
        elif row == columns - 1:
            direction = -1
        row += direction
    # Считываем буквы по порядку строк и колонок
    decoded_msg = ''
    for i in range(len(encoded_msg)):
        row, col = divmod(i, columns)
        decoded_msg += ladder[col][row]
    return decoded_msg


msg = 'МЕЕЕСНЬМТПЦСНРЧЯТЫЗДОЕЕТОЫЕТИСООВЧЛИГЧСЕСИВКИЕОИЕКЛВСАУОНСЕЛОЬЯПНМБИТСОЙНЗОИЕЕЕНФВДОАЛЕНСМО'
# columns = 4
# encoded = encode_ladder(msg, columns)
# print(encoded)
# decoded = decode_ladder(encoded, columns)
# print(decoded)

for i in range(2, len(msg) // 2):
    encoded = decode_ladder(msg, i)
    print(i, encoded)