
import sys
sys.path.append("d:\\GH\\university\\term7\\Pat\\lab3\\Domain")
sys.path.append("d:\\GH\\university\\term7\\Pat\\lab3\\Factories")

from MembershipFactory import MembershipFactory
from PersonalTrainingMembershipFactory import PersonalTrainingMembershipFactory
from GymPlusPoolMembershipFactory import GymPlusPoolMembershipFactory
from GymMembershipFactory import GymMembershipFactory


def main():
    print(">>> Добро пожаловать в FitnessClub CRM <<<\n")

    print("> Введите тип членства, которое вы хотите создать: ")

    print("> G - Тренажерный зал")
    print("> P - Тренажерный зал + Бассейн")
    print("> T - Персональные тренировки")

    membershipType = input()

    factory = get_factory(membershipType)

    membership = factory.GetMembership()

    print("\n> Созданное вами членство: \n")

    print(
        f"\tИмя:\t\t{membership.Name}\n" +
        f"\tОписание:\t{membership.Description}\n" +
        f"\tЦена:\t\t{membership.GetPrice()}")

    input()

def get_factory(membership_type):
    membership_type = membership_type.lower()
    if membership_type == "g":
        return GymMembershipFactory(100, "Базовое членство")
    elif membership_type == "p":
        return GymPlusPoolMembershipFactory(250, "Членство по выгодной цене")
    elif membership_type == "t":
        return PersonalTrainingMembershipFactory(400, "Лучший выбор для профессионалов")
    else:
        return None

if __name__ == "__main__":
    main()