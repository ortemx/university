'''
Абстрактный класс изображения интерфейса
'''
from abc import ABC, abstractmethod

class Image(ABC):
    '''
    Абстрактный класс изображения интерфейса
    '''
    @property
    @abstractmethod
    def image(self):
        '''
        Возвращает изображение
        '''
