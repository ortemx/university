from abc import ABC, abstractmethod

# Abstract interface IMembership
class IMembership(ABC):
    @property
    @abstractmethod
    def Name(self):
        pass

    @property
    @abstractmethod
    def Description(self):
        pass

    @Description.setter
    @abstractmethod
    def Description(self, value):
        pass

    @abstractmethod
    def GetPrice(self):
        pass
