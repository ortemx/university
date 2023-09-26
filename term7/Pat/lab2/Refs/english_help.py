'''
Класс справки английского интерфейса
Product C2
'''

from abstract_help import Help

class EnglishHelp(Help):
    '''
    Справка на английском языке
    '''
    def __init__(self):
        self._help = "Справка английского интерфейса"
    @property
    def help(self):
        return self._help
