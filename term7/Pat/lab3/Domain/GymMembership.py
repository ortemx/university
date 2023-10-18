from IMembership import IMembership

class GymMembership(IMembership):
    def __init__(self, price):
        self._name = "Gym membership"
        self._price = price

    @property
    def Name(self):
        return self._name

    @property
    def Description(self):
        return self._description

    @Description.setter
    def Description(self, value):
        self._description = value

    def GetPrice(self):
        return self._price