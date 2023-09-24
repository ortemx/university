from heapq import heappop, heappush

class Node:
    def __init__(self, symbol, probability):
        self.symbol = symbol
        self.probability = probability
        self.left = None
        self.right = None

def build_fano_tree(symbols):
    if len(symbols) == 1:
        return symbols[0]

    # Отсортировать символы по убыванию вероятностей
    symbols = sorted(symbols, key=lambda x: x.probability, reverse=True)

    # Рекурсивно построить дерево Фано
    return build_fano_tree_helper(symbols)

def build_fano_tree_helper(symbols):
    if len(symbols) == 1:
        return symbols[0]

    # Найти точку разделения алфавита
    total_probability = sum(symbol.probability for symbol in symbols)
    target_probability = total_probability / 2
    current_probability = 0
    split_index = None

    for i in range(len(symbols)):
        current_probability += symbols[i].probability
        if current_probability >= target_probability:
            split_index = i
            break

    # Разделить алфавит на две части
    left_symbols = symbols[:split_index + 1]
    right_symbols = symbols[split_index + 1:]

    # Рекурсивно построить левое и правое поддерево
    left_subtree = build_fano_tree_helper(left_symbols)
    right_subtree = build_fano_tree_helper(right_symbols)

    # Создать узел, соединяющий левое и правое поддерево
    root = Node(None, total_probability)
    root.left = left_subtree
    root.right = right_subtree

    return root

def encode_fano_tree(root, code=''):
    if root.symbol is not None:
        # Листовой узел
        return {root.symbol: code}
    else:
        # Внутренний узел
        code_map = {}
        code_map.update(encode_fano_tree(root.left, code + '0'))
        code_map.update(encode_fano_tree(root.right, code + '1'))
        return code_map

# Пример использования
text = "Hello, world!"
symbol_counts = {}

for symbol in text:
    symbol_counts[symbol] = symbol_counts.get(symbol, 0) + 1

symbols = [Node(symbol, count / len(text)) for symbol, count in symbol_counts.items()]
fano_tree = build_fano_tree(symbols)
code_map = encode_fano_tree(fano_tree)

for symbol, code in code_map.items():
    print(f"Symbol: {symbol}, Code: {code}")