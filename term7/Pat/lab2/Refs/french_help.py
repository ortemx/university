'''
Класс справки французского интерфейса
Product C3
'''

from abstract_help import Help

class FrenchHelp(Help):
    '''
    Справка на французском языке
    '''
    def __init__(self):
        self._help = "Справка французского интерфейса"
    @property
    def help(self):
        return self._help
