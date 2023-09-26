'''
Класс текста русского интерфейса
ProductA1
'''

from abstract_text import Text

class RussianText(Text):
    '''
    Русский текст
    '''
    def __init__(self):
        self._text = "Русский текст"
    @property
    def text(self):
        return self._text
