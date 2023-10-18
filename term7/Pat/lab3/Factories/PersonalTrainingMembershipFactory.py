from MembershipFactory import MembershipFactory
import sys
sys.path.append("d:\\GH\\university\\term7\\Pat\\lab3\\Domain")

from PersonalTrainingMembership import PersonalTrainingMembership

class PersonalTrainingMembershipFactory(MembershipFactory):
    def __init__(self, price, description):
        self._price = price
        self._description = description

    def GetMembership(self):
        membership = PersonalTrainingMembership(self._price)
        membership.description = self._description
        return membership
