'''
Абстрктный класс фабрики интерфейса
'''

from abc import ABC, abstractmethod

class InterfaceFactory(ABC):
    '''
    Фабрика интерфейса
    '''
    @abstractmethod
    def create_text(self):
        '''
        Создание текста
        '''

    @abstractmethod
    def create_image(self):
        '''
        Создание изображения
        '''

    @abstractmethod
    def create_help(self):
        '''
        Создание справки
        '''
