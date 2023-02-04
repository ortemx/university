# 
input_str: str = "Конышев_Артём_Евгеньевич_302_1"

count:int = 0

n:int = 5
m:int = 6

table = []

for i in range(n):
    table.append([])
    for j in range(m):
        if count >= len(input_str):
            table[i].append("_")
        else:
            table[i].append(input_str[count])
        count += 1

for i in range(n):
    for j in range(m):
        print(table[i][j], end="")
    print()

output_str:str = ""


for j in range(m):
    for i in range(n):
        output_str += table[i][j]

print("output_str = ", output_str)
