'''
Класс изображения русского интерфейса
Product B1
'''

from abstract_image import Image

class RussianImage(Image):
    '''
    Изобажение русского интерфейса
    '''
    def __init__(self):
        self._image = "Изобажение русского интерфейса"
    @property
    def image(self):
        return self._image
