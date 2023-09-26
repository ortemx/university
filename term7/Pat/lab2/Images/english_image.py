'''
Класс изображения английского интерфейса
Product B2
'''

from abstract_image import Image

class EnglishImage(Image):
    '''
    Изобажение английского интерфейса
    '''
    def __init__(self):
        self._image = "Изобажение английского интерфейса"
    @property
    def image(self):
        return self._image
