import math

commands = {
    "Barcelona": {
        "year": 1899,
        "victory_probability": 0
    },
    "Real Madrid": {
        "year": 1899,
        "victory_probability": 0
    },
    "Real Sociedad": {
        "year": 1903,
        "victory_probability": 0
    },
    "Atletico Madrid": {
        "year": 1903,
        "victory_probability": 0
    },
    "Athletic Bilbao": {
        "year": 1898 ,
        "victory_probability": 0
    },
    "Betis": {
        "year": 1907,
        "victory_probability": 0
    },
    "Osasuna": {
        "year": 1920,
        "victory_probability": 0
    },
    "Rayo Vallecano": {
        "year": 1924,
        "victory_probability": 0
    },
    "Villarreal": {
        "year": 1923,
        "victory_probability": 0
    },
    "Mallorca": {
        "year": 1916,
        "victory_probability": 0
    },
    "Valencia": {
        "year": 1919,
        "victory_probability": 0
    },
    "Real Valladolid": {
        "year": 1928,
        "victory_probability": 0
    },
    "Almería": {
        "year": 1989,
        "victory_probability": 0
    },
    "Girona": {
        "year": 1930,
        "victory_probability": 0
    },
    "Getafe": {
        "year": 1946,
        "victory_probability": 0
    },
    "Espanyol": {
        "year": 1900,
        "victory_probability": 0
    },
    "Celta": {
        "year": 1923,
        "victory_probability": 0
    },
    "Sevilla": {
        "year": 1905,
        "victory_probability": 0
    },
    "Cadiz": {
        "year": 1910,
        "victory_probability": 0
    },
    "Elche": {
        "year": 1923,
        "victory_probability": 0
    },
    "Las Palmas": {
        "year": 1949,
        "victory_probability": 0
    },
    "Eibar": {
        "year": 1940,
        "victory_probability": 0
    },
    "Levante": {
        "year": 1909,
        "victory_probability": 0
    },
    "Burgos CF": {
        "year": 1985,
        "victory_probability": 0
    },
    "Deportivo Alavés": {
        "year": 1921,
        "victory_probability": 0
    },
    "Granada CF": {
        "year": 1931,
        "victory_probability": 0
    },
    "Cartagena": {
        "year": 1995,
        "victory_probability": 0
    },
    "Albacete": {
        "year": 1940,
        "victory_probability": 0
    },
    "Leganes": {
        "year": 1928,
        "victory_probability": 0
    },
    "FC Andorra": {
        "year": 1942,
        "victory_probability": 0
    },
    "Huesca": {
        "year": 1910,
        "victory_probability": 0
    },
    "Villarreal B": {
        "year": 1923,
        "victory_probability": 0
    },
    "Real Oviedo": {
        "year": 1926,
        "victory_probability": 0
    },
    "Sporting Gijón": {
        "year": 1905,
        "victory_probability": 0
    },
    "Mirandés": {
        "year": 1927,
        "victory_probability": 0
    },
    "Zaragoza": {
        "year": 1932,
        "victory_probability": 0
    },
    "Tenerife": {
        "year": 1912,
        "victory_probability": 0
    },
    "Ponferradina": {
        "year": 1922,
        "victory_probability": 0
    },
    "Lugo": {
        "year": 1953,
        "victory_probability": 0
    },
    "Santander": {
        "year": 1913,
        "victory_probability": 0
    },
    "Malaga": {
        "year": 1904,
        "victory_probability": 0
    },
    "UD Ibiza": {
        "year": 2015,
        "victory_probability": 0
    }
}


step: float = math.log(100) / 42
count: float = math.log(100) - step
print ("step =", step)
probability: float = 0
for key in commands.keys():
    probability = math.exp(count)
    # commands[key]["victory_probability"] = math.exp()
    print(probability, count)
    # count += 0.109523809
    count -= step




referees = [
    "Pedro Revuelta",
    "Rodrigo Parra",
    "Martín Pereyra",
    "Juanantonio Ramírez",
    "Joséfrancisco Carrizo",
    "Joséantonio Sandoval",
    "Adrián Espejo",
    "Salvador Morales",
    "Alfonso Toledo",
    "Alberto Ortizdezárate",
    "Manuel Núñez",
    "Miguelángel Castillo",
    "Agustín Delrío",
    "Enrique Valenzuela",
    "Roberto Rico",
    "Martín Nieto",
    "Sergio Río",
    "Víctor Cordero",
    "Guillermo Robles",
    "Juanluis Padilla",
    "Gerardo Lagos",
    "Rafael Vera",
    "Mario Díaz",
    "Benito Pinto",
    "Daniel Páez",
    "Juanjosé Vera",
    "Santiago Alvarado",
    "Miguelángel Soriano",
    "Antonio Alarcón",
    "Tomás Salazar",
    "Adolfo Ortiz",
    "Francisco Henríquez",
    "Joséfrancisco Medina",
    "Héctor Vargas",
    "Juancarlos Poblete",
    "Franciscojosé Robles",
    "Aarón Valenzuela",
    "Esteban Núñez",
    "Daniel Tebar",
    "Óscar Ávila",
    "Ricardo Valenzuela",
    "Lucas Paz",
    "Bernardo Botella",
    "Vicente Peña",
    "Vicente Peralta",
    "Víctormanuel Calderón",
    "Juancarlos Segura",
    "Ramón Lozano",
    "Alfredo Castro",
    "Jesús Morales",
    "Carmelo Guzmán",
    "Miguel Delafuente",
    "Juanjosé Coronel",
    "Jorge Luna",
    "Vicente Blanco",
    "Joséángel Silva",
    "Valentín Arroyo",
    "Jaime Murillo",
    "Joséantonio Ferreyra",
    "Juanantonio Morales",
    "Bernardo Valdéz",
    "Jaime Santos",
    "Guillermo Segura"
]
