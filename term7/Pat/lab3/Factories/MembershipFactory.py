from abc import ABC, abstractmethod
import sys
sys.path.append("d:\\GH\\university\\term7\\Pat\\lab3\\")
from Domain.IMembership import IMembership
class MembershipFactory(ABC):
    @abstractmethod
    def GetMembership(self):
        pass
