from random import *
from collections import Counter
# a = Counter([0, 1, 2, 1, 0])
# b = Counter([0, 1, 1])
# c = a - b  # ignores items in b missing in a
# print(list(c.elements()))  # -> [0, 2]


mainTeam = [i for i in range(1, 12)]
reserveTeam = [i for i in range(12, 17)]

print("основная команда: ", mainTeam)
print("запасная команда: ", reserveTeam)

tempTeam = sample(mainTeam, 3)
tempTeam.sort()
print("список игроков из основной команды на замену: ", tempTeam)

mainTeam = list((Counter(mainTeam) - Counter(tempTeam)).elements())

tempTeam = sample(reserveTeam, 3)
tempTeam.sort()
print("список игроков из запасной команды на замену: ", tempTeam)

mainTeam.extend(tempTeam)
print("основная команда поле замены: ", mainTeam)

playerNumber: int = int(input("введите номер игрока основной команды для удаления "))

if playerNumber in mainTeam:
    mainTeam.remove(playerNumber)
    print("основная команда поле удаления игрока: ", mainTeam)
else:
    print("игрока с таким номером в основной команде нет")


