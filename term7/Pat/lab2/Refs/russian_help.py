'''
Класс справки русского интерфейса
Product C1
'''

from abstract_help import Help

class RussianHelp(Help):
    '''
    Справка на русском языке
    '''
    def __init__(self):
        self._help = "Справка русского интерфейса"
    @property
    def help(self):
        return self._help
