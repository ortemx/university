import sys
sys.path.append("d:\\GH\\university\\term7\\Pat\\lab3\\Domain")
from GymMembership import GymMembership
from MembershipFactory import MembershipFactory

class GymMembershipFactory(MembershipFactory):
    def __init__(self, price, description):
        self._price = price
        self._description = description

    def GetMembership(self):
        membership = GymMembership(self._price)
        membership.Description = self._description
        return membership
