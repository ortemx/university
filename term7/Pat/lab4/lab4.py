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
