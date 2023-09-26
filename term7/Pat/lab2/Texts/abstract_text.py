'''
Абстрактный класс текста интерфейса
'''

from abc import ABC, abstractmethod
class Text(ABC):
    '''
    Абстрактный класс текста интерфейса
    '''
    @property
    @abstractmethod
    def text(self):
        '''
        Возвращает текст
        '''
