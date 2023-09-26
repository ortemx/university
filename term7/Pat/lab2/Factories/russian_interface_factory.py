'''
Фабрика русского интерфейса
ConcreteFactory1
'''
import sys
from abstract_interface_factory import InterfaceFactory
sys.path.insert(0, 'd:/GH/university/term7/Pat/lab2/Texts')
sys.path.insert(0, 'd:/GH/university/term7/Pat/lab2/Refs')
sys.path.insert(0, 'd:/GH/university/term7/Pat/lab2/Images')

from russian_text import RussianText
from russian_image import RussianImage
from russian_help import RussianHelp
class RussianInterfaceFactory(InterfaceFactory):
    '''
    Фабрика русского интерфейса
    '''

    def create_text(self):
        return RussianText()

    def create_image(self):
        return RussianImage()

    def create_help(self):
        return RussianHelp()

print(RussianInterfaceFactory().create_text().text)
print(RussianInterfaceFactory().create_image().image)
print(RussianInterfaceFactory().create_help().help)
