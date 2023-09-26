'''
Класс текста французского интерфейса
ProductA3
'''

from abstract_text import Text

class FrenchText(Text):
    '''
    Французский текст
    '''
    def __init__(self):
        self._text = "Французский текст"
    @property
    def text(self):
        return self._text
