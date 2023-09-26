'''
Паттерн «Абстрактная фабрика»
'''

from abc import ABC, abstractmethod
from term7.Pat.lab2.Factories.abstract_interface_factory import InterfaceFactory



















class EnglishInterfaceFactory(InterfaceFactory):
    '''
    Фабрика английского интерфейса
    '''
    def create_text(self):
        return EnglishText()

    def create_image(self):
        return EnglishImage()

    def create_help(self):
        return EnglishHelp()

class FrenchInterfaceFactory(InterfaceFactory):
    '''
    Фабрика французского интерфейса
    '''
    def create_text(self):
        return FrenchText()

    def create_image(self):
        return FrenchImage()

    def create_help(self):
        return FrenchHelp()

concrete_interface = RussianInterfaceFactory()
