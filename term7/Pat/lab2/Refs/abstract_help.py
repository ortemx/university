'''
Абстрактный класс справки пользователя
'''

from abc import ABC, abstractmethod

class Help(ABC):
    '''
    Абстрактный класс справки интерфейса
    '''
    @property
    @abstractmethod
    def help(self):
        '''
        Возвращает текст справки
        '''
