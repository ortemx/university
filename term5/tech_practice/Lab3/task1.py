import json
from pyowm import OWM
from pyowm.utils.config import get_default_config
import requests


def writeDataInJson(_data: list, fileName: str) -> None:
    with open(fileName, "w", encoding='utf-8') as jsonfile:
        json.dump(_data, jsonfile, indent=4, ensure_ascii=False)
    jsonfile.close()


def readDataFromJson(fileName: str) -> list:
    _data = []
    with open(fileName, "r", encoding='utf-8') as jsonfile:
        _data = json.load(jsonfile)

    return _data


def getModifiedCitiesList(cities: list) -> list:
    wrong_cities = ['Алупка', 'Алушта', 'Армянск', 'Балаклава', 'Джанкой', 'Дмитриев', 'Евпатория', 'Инкерман', 'Керчь',
                    'Красноперекопск', 'Межгорье', 'Саки', 'Симферополь', 'Старый Крым', 'Судак', 'Феодосия',
                    'Циолковский', 'Щёлкино']

    # for city in cities:
    #     city.pop('coords')
    #     city.pop('district')
    #     city.pop('subject')
    #
    #     print(city['name'])
    #
    #     params = {
    #         'q': city['name'] + ",RU",
    #         'appid': "16d624f54d5f51bed4088e53014af4e3"
    #     }
    #
    #     response = requests.get("https://api.openweathermap.org/data/2.5/weather", params)
    #     if 'name' not in response.json():
    #         continue
    #
    #     eng_name = response.json()['name']
    #     cityID = response.json()['id']
    #
    #     city['eng_name'] = eng_name
    #     city['cityID'] = cityID
    #
    # print("wrong Cities: ", wrong_cities)

    # for w_city in wrong_cities:
    #     for city in cities:
    #         if w_city == city["name"]:
    #             cities.remove(city)

    return cities


def getWordEnding(number: int) -> str:
    return "человека" if str(number)[-1] in ["2", "3", "4"] else "человек"


def printWeatherInformation(cities: list, population: int, status: str) -> None:
    apiKey = "8543aaba717a4093d9776b21f90aeca3"
    config_dict = get_default_config()
    config_dict['language'] = 'ru'

    owm = OWM(apiKey, config_dict)
    mgr = owm.weather_manager()

    cities = [city for city in cities if city["population"] >= population]

    count = 0
    while count < cities.__len__():
        citiesList = cities[count:count + 20:]
        citiesIDList = [city["cityID"] for city in citiesList]

        observation = mgr.weather_at_ids(citiesIDList)
        for i in range(len(observation)):
            if observation[i].weather.status == status:
                city_name = citiesList[i]["name"]
                city_population = citiesList[i]["population"]
                correct_word_form = getWordEnding(city_population)
                weather_status = statusList[status]
                print(f"В городе {city_name} c населением {city_population} {correct_word_form} сейчас {weather_status}")

        count += 20


# ru_cities = readDataFromJson("russian_cities.json")
# ru_cities = getModifiedCitiesList(ru_cities)

# writeDataInJson(ru_cities, "russian_cities_update.json")

ru_cities = readDataFromJson("russian_cities_update.json")

statusList = {
    "Rain": "идёт дождь",
    "Snow": "снег",
    "Clouds": "облачно"
}

while True:
    _population = int(input("Введите требуемое население: "))
    if _population == 0:
        break

    print(statusList)
    _weather_status = input("Введите интересующую погоду: ")

    printWeatherInformation(ru_cities, _population, _weather_status)

