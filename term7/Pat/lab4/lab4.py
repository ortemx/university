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
from abc import ABC, abstractmethod

class LengthConverter(ABC):
    @abstractmethod
    def convert(self, length: float) -> float:
        pass
  
  
class MeterConverter:
    def convert_to_meter(self, length: float) -> float:
        return length

    def convert_to_feet(self, length: float) -> float:
        return length * 3.28084 * 3.28084


class MeterToFeetAdapter(LengthConverter):
    def __init__(self, meter_converter: MeterConverter):
        self.meter_converter = meter_converter

    def convert(self, length: float) -> float:
        return self.meter_converter.convert_to_feet(length)
    


meter_converter = MeterConverter()
adapter = MeterToFeetAdapter(meter_converter)

area_in_square_meter = 100
area_in_square_feet = adapter.convert(area_in_square_meter)

print(f"{area_in_square_meter} square meters = {area_in_square_feet} square feet")
