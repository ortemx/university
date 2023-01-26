import json
from datetime import date, datetime
from time import sleep
import itertools
import requests
from requests import Response
import matplotlib as mpl
import matplotlib.pyplot as plt
from acsess import token


def getAllMembers(group_id: int) -> list:
    address: str = 'https://api.vk.com/method/'
    method: str = 'groups.getMembers'
    version: float = 5.131
    count: int = 1000
    fields: str = 'bdate, universities, sex'
    offset: int = 0
    params: dict = dict(access_token=token, group_id=group_id, v=version, fields=fields, count=count)

    all_members: list = []

    while True:
        params['offset'] = offset
        response: Response = requests.get(address + method, params)
        count_of_members: int = response.json()["response"]['count']
        all_members.extend(response.json()['response']['items'])

        print("\rКоличество подписчиков:", count_of_members, "\tОбработано:", offset, end="")
        sleep(0.200)
        offset += 1000
        if offset > count_of_members:
            break

    return all_members


def writeDataInJsonFile(data: list, fileName: str) -> None:
    with open(fileName, "w", encoding='utf-8') as jsonfile:
        json.dump(data, jsonfile, indent=4, ensure_ascii=False)
    jsonfile.close()


def readDataFromJsonFile(fileName: str) -> list:
    with open(fileName, "r", encoding='utf-8') as jsonfile:
        data: list = json.load(jsonfile)

    return data


def getAge(birthdate: str) -> int:
    if len(birthdate) > 7:
        today: date = date.today()
        birthdate = datetime.strptime(birthdate, "%d.%m.%Y")
        return today.year - birthdate.year - ((today.month, today.day) < (birthdate.month, birthdate.day))
    return -1


def updateAgeDict(birthdate: str, ages: dict) -> None:
    age: int = getAge(birthdate)
    if age != -1:
        if age <= 18:
            ages["0 - 18"] += 1
        elif age <= 25:
            ages["19 - 25"] += 1
        elif age <= 35:
            ages["26 - 35"] += 1
        elif age <= 45:
            ages["36 - 45"] += 1
        elif age <= 55:
            ages["46 - 55"] += 1
        else:
            ages["55 and older"] += 1
    else:
        ages["unspecified"] += 1


def updateUniversityDict(universities_of_user: list, all_universities: dict) -> None:
    count_of_universities_of_user = len(universities_of_user)
    if count_of_universities_of_user == 0:
        all_universities["unspecified"] += 1
    else:
        for university in universities_of_user:
            university_id: str = university["id"]
            if university_id in all_universities:
                all_universities[university_id] += 1
            else:
                all_universities[university_id] = 1


def processingData(dataList: list, _ageDict: dict, _sexDict: dict, _universityDict: dict) -> None:
    for data in dataList:
        if 'bdate' in data:
            updateAgeDict(data['bdate'], _ageDict)
        else:
            _ageDict["unspecified"] += 1
        if 'sex' in data:
            _sexDict[str(data["sex"])] += 1
        else:
            _sexDict["0"] += 1
        if 'universities' in data:
            updateUniversityDict(data['universities'], _universityDict)
        else:
            _universityDict["unspecified"] += 1


def getUniversitiesTitles(city_id: int, universities_id: list) -> dict:
    address: str = "https://api.vk.com/method/"
    method: str = "database.getUniversities"
    params: dict = dict(access_token=token, country_id=1, city_id=city_id, v=5.131, count=100)
    response: Response = requests.get(address + method, params)
    all_universities: dict = response.json()['response']['items']
    universities_titles: dict = {}

    for university_id in universities_id:
        for university in all_universities:
            if university_id == university['id']:
                universities_titles[university_id] = university['title']

    return universities_titles


def getModifiedUniversityDict(city_id: int, universities: dict, count_of_MP_universities: int) -> dict:
    MP_universities: dict = dict(itertools.islice(universities.items(), 1, count_of_MP_universities))
    MP_universities_titles: dict = getUniversitiesTitles(city_id, [*MP_universities])

    count_of_other_universities = 0

    for count in list(universities.values())[count_of_MP_universities:]:
        count_of_other_universities += count

    print("Количество остальных университетов:", count_of_other_universities)

    top_and_other_universities = dict(zip(MP_universities_titles.values(),
                                          MP_universities.values()))
    top_and_other_universities["other"] = count_of_other_universities

    return top_and_other_universities


def buildingBarChart(title: str, filename: str, keys: list, values: list) -> None:
    dpi = 160
    fig = plt.figure(dpi=dpi, figsize=(1024 / dpi, 1024 / dpi))
    mpl.rcParams.update({'font.size': 10})
    ax = plt.axes()
    ax.yaxis.grid(True, zorder=0)
    plt.title(title)

    plt.bar(keys, values, zorder=1)
    plt.xticks(keys)
    fig.autofmt_xdate(rotation=25)
    fig.savefig(filename)


def buildingPieChart(title: str, filename: str, keys: list, values: list) -> None:
    dpi = 160
    fig = plt.figure(dpi=dpi, figsize=(1024 / dpi, 1024 / dpi))
    mpl.rcParams.update({'font.size': 10})
    plt.title(title)
    plt.pie(values, autopct='%.1f', radius=1.1)
    plt.legend(
        bbox_to_anchor=(0.3, 0.1),
        loc=10,
        fontsize=7, labels=keys)
    fig.savefig(filename)


cities_ids: dict[str, int] = {
    "Нижний Новгород": 95,
    "Чебоксары": 157,
    "Казань": 60,
    "Пенза": 109,
    "Ульяновск": 149,
    "Самара": 123,
    "Рязань": 122,
    "Саратов": 125,
    "Уфа": 151,
    "Челябинск": 158
}

age_groups = {
    "0 - 18": 0,
    "19 - 25": 0,
    "26 - 35": 0,
    "36 - 45": 0,
    "46 - 55": 0,
    "55 and older": 0,
    "unspecified": 0
}

sex_dict = {
    "0": 0,  # пол не указан
    "1": 0,  # женский
    "2": 0   # мужской
}

university_dict = {
    "unspecified": 0
}

file_path = "allMembers.json"

# allMembers = getAllMembers(62298989)
# writeDataInJson(allMembers, filePath)

group_members: list = readDataFromJsonFile(file_path)

processingData(group_members, age_groups, sex_dict, university_dict)

university_dict = {k: v for k, v in sorted(university_dict.items(), key=lambda item: item[1], reverse=True)}

university_dict = getModifiedUniversityDict(151, university_dict, 11)

charts_titles = (
    'Распределение подписчиков по возрасту',
    'Распределение подписчиков по полу',
    'Распределение подписчиков по университетам'
)

buildingBarChart(charts_titles[0], 'barsAge.png', [*age_groups.keys()][:6], list(age_groups.values())[:6])
buildingBarChart(charts_titles[1], 'barsSex.png', ["Женщины", "Мужчины"], list(sex_dict.values())[1:])
buildingBarChart(charts_titles[2], 'barsUniversity.png', [*university_dict.keys()], list(university_dict.values()))

buildingPieChart(charts_titles[0], 'pieAge.png', [*age_groups.keys()][:6], list(age_groups.values())[:6])
buildingPieChart(charts_titles[1], 'pieSex.png', ["Женщины", "Мужчины"], list(sex_dict.values())[1:])
buildingPieChart(charts_titles[2], 'pieUniversity.png', [*university_dict.keys()], list(university_dict.values()))
