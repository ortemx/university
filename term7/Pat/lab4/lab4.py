'''
Разработать приложение для конвертации длин из одной системы
измерения в другую (например, из метров в футы) с использованием паттерна
"Адаптер".
Шаги выполнения:
1 - Создайте целевой интерфейс, который будет описывать методы для
конвертации длин.
2 - Создайте адаптируемый класс, который предоставляет
функциональность для работы с длинами в одной системе измерения (например,
метры).
3 - Создайте адаптер, который реализует целевой интерфейс и использует
адаптируемый класс для выполнения операций конвертации.
4 - Разработайте клиентское приложение, которое использует адаптер для
конвертации длин из одной системы измерения в другую (например, из метров в
футы).
Протестируйте приложение, убедившись в правильности конвертации длин
и корректной работе адаптера.

'''


class LengthConverter:
    def convert_meters_to_feet(self, meters):
        pass

    def convert_feet_to_meters(self, feet):
        pass



class MetricLength:
    def __init__(self):
        pass
        # self.length = length

    def get_length(self):
        return self.length

    def set_length(self, length):
        self.length = length


class MetricToImperialAdapter(LengthConverter):
    def __init__(self, metric_length):
        self.metric_length = metric_length

    def convert_meters_to_feet(self, meters):
        self.metric_length.set_length(meters)
        return self.metric_length.get_length() * 3.28084

    def convert_feet_to_meters(self, feet):
        self.metric_length.set_length(feet / 3.28084)
        return self.metric_length.get_length()


class LengthConversionApp:
    def __init__(self, converter):
        self.converter = converter

    def convert_length(self, length, from_unit, to_unit):
        if from_unit == "meters" and to_unit == "feet":
            result = self.converter.convert_meters_to_feet(length)
            return f"{length} meters is equal to {result} feet."
        elif from_unit == "feet" and to_unit == "meters":
            result = self.converter.convert_feet_to_meters(length)
            return f"{length} feet is equal to {result} meters."
        else:
            return "Unsupported conversion."


adapter = MetricToImperialAdapter(MetricLength())  
app = LengthConversionApp(adapter) 

result = app.convert_length(10, "meters", "feet") 
print(result)  

result = app.convert_length(20, "feet", "meters") 
print(result) 
