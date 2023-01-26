import requests
import re

import matplotlib.pyplot as plt

# data start

token = '208ad992208ad992208ad99226239bb3562208a208ad99243e794bc2bb4c12a6704d9f3'
version = 5.131
id = 62298989
fields = 'sex,universities,bdate'
all_sub = []


# function request

def request_sub(temp, offset=0):
    response = requests.get('https://api.vk.com/method/groups.getMembers',
                            params={
                                'access_token': token,
                                'v': version,
                                'group_id': id,
                                'fields': fields,
                                'count': 1000,
                                'offset': offset
                            }
                            )

    return response.json()['response'][temp]


# functions

def age(bdate):
    try:
        if (bdate.count(".") == 2):
            # if (bdate.find('.') != bdate.rfind('.')):
            tmp = bdate[bdate.rfind('.') + 1: len(bdate)]
            tmp = 2022 - int(tmp)

        return tmp

    except:
        return -1


def list_age_group(list_age, interval):
    try:

        left_border = int(interval[0: interval.find('-')])
        right_border = int(interval[interval.find('-') + 1: len(interval)])

    except:
        left_border = -2
        right_border = 0

    if interval.find('+') != -1:
        left_border = int(interval[0: interval.find('+')])
        right_border = left_border * 1000

    count = 0

    for i in range(0, len(list_age)):
        if list_age[i] > left_border and list_age[i] < right_border:
            count += 1

    return count


def list_sex_group(list_sex):
    count_1 = 0
    count_2 = 0
    list_sex_all = []

    for i in range(0, len(list_sex)):
        if list_sex[i] == 1:
            count_1 += 1
        elif list_sex[i] == 2:
            count_2 += 1

    list_sex_all.append(count_1)
    list_sex_all.append(count_2)

    return list_sex_all


def list_uni_group(list_uni, list_id):
    count = 0
    uni_value = []
    uni_name = []
    temp = []
    all_data = []

    for i in range(0, len(list_id)):
        count = 0
        for j in range(0, len(list_uni)):
            if list_uni[j]['id'] == list_id[i]:
                temp.append(list_uni[j]['name'])
                # print(list_uni[j]['id'], "--------------", list_id[i])
                count += 1

        uni_name.append(temp[0])
        uni_value.append(count)

        temp.clear()

    all_data.append(uni_name)
    all_data.append(uni_value)

    return all_data


def sort_uni(data_names, data_values):
    list_all_data = []

    for i in range(0, len(data_values)):
        for j in range(0, len(data_values) - i - 1):
            if data_values[j] < data_values[j + 1]:
                data_values[j + 1], data_values[j] = data_values[j], data_values[j + 1]
                data_names[j + 1], data_names[j] = data_names[j], data_names[j + 1]

    list_all_data.append(data_names)
    list_all_data.append(data_values)

    return list_all_data


def trend(data_names, data_values):
    list_all_data = []
    list_values = []
    list_names = []
    count = 0

    for i in range(0, len(data_values)):
        if i < 10:
            list_values.append(data_values[i])
            list_names.append(data_names[i])
        else:

            if data_values[i] > data_values[0] / 30:
                count += data_values[i]

    # for i in range(0, len(list_values)):
    # all -= list_values[i]

    list_values.append(count)
    list_names.append('Другое')

    list_all_data.append(list_names)
    list_all_data.append(list_values)

    return list_all_data


# start

temp = 'count'
offset = 0
count_sub = request_sub(temp)
list_age_sub = []
list_sex_sub = []

# print(request_sub(temp))

temp = 'items'

while offset <= count_sub:
    data = request_sub(temp, offset)
    all_sub.extend(data)
    print(count_sub, offset)
    offset += 1000

# age

data_names_age = ['0-18', '18-25', '25-35', '35-50', '50+', 'Другое']
data_values_age = []

for i in range(0, len(all_sub)):
    try:
        temp = age(all_sub[i]['bdate'])
        list_age_sub.append(temp)

    except:
        pass

for i in range(0, len(data_names_age)):
    data_values_age.append(list_age_group(list_age_sub, data_names_age[i]))

# sex


for i in range(0, len(all_sub)):
    try:
        list_sex_sub.append((all_sub[i]['sex']))

    except:
        pass

data_names_sex = ['Женский', 'Мужской']
data_values_sex = list_sex_group(list_sex_sub)

# universities

list_uni_sub = []
list_id_uni = []

for i in range(0, len(all_sub)):
    try:
        list_uni_sub.append(all_sub[i]['universities'][0])
        list_id_uni.append(all_sub[i]['universities'][0]['id'])
        # print (all_sub[i]['universities'][j])
    except:
        pass

# print(list_uni_sub)
# print("-----------")
# print(list_id_uni)

set_id_uni = set(list_id_uni)

unique_id = []

for i in set_id_uni:
    unique_id.append(i)

# print(set_id_uni)

data_uni = list_uni_group(list_uni_sub, unique_id)
data_uni = sort_uni(data_uni[0], data_uni[1])

data_uni = trend(data_uni[0], data_uni[1])

# print(data_uni)

# charts

# charts_age

explode2 = (0.3, 0.2, 0.15, 0.1, 0)

plt.subplot(2, 3, 2)
plt.pie(data_values_age, labels=data_names_age, autopct='%1.1f%%', shadow=True,
        wedgeprops={'lw': 1, 'ls': '--', 'edgecolor': "k"}, rotatelabels=True)
plt.title("Возраст")

plt.subplot(2, 3, 5)
plt.bar(data_names_age, data_values_age)
plt.title("Возраст")
plt.xticks(rotation=90)

plt.show()

# charts_sex

explode1 = (0.5, 0)

plt.subplot(2, 3, 1)
plt.pie(data_values_sex, labels=data_names_sex, autopct='%1.1f%%', shadow=True, explode=explode1,
        wedgeprops={'lw': 1, 'ls': '--', 'edgecolor': "k"}, rotatelabels=True)
plt.title("Пол")

plt.subplot(2, 3, 4)
plt.bar(data_names_sex, data_values_sex)
plt.title("Пол")

plt.show()

# charts_universities

plt.subplot(2, 3, 3)
plt.pie(data_uni[1], labels=data_uni[0], autopct='%1.1f%%', shadow=True,
        wedgeprops={'lw': 1, 'ls': '--', 'edgecolor': "k"}, rotatelabels=True)
plt.title("Университет")

plt.subplot(2, 3, 6)
plt.bar(data_uni[0], data_uni[1])
plt.title("Университет")
plt.xticks(rotation=90)

plt.show()

# print(all_sub[9])







