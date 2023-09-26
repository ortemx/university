'''
Класс текста английского интерфейса
ProductA2
'''

from abstract_text import Text

class EnglishText(Text):
    '''
    Английский текст
    '''
    def __init__(self):
        self._text = "Английский текст"
    @property
    def text(self):
        return self._text
