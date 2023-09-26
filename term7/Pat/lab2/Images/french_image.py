'''
Класс изображения французского интерфейса
Product B3
'''

from abstract_image import Image

class FrenchImage(Image):
    '''
    Изобажение французского интерфейса
    '''
    def __init__(self):
        self._image = "Изобажение французского интерфейса"
    @property
    def image(self):
        return self._image
