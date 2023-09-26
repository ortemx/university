'''
Паттерн «Абстрактная фабрика»
'''

from abc import ABC, abstractmethod

class InterfaceFactory(ABC):
    '''
    Фабрика интерфейса
    '''
    @abstractmethod
    def create_text(self):
        '''
        Создание текста
        '''

    @abstractmethod
    def create_image(self):
        '''
        Создание изображения
        '''

    @abstractmethod
    def create_help(self):
        '''
        Создание справки
        '''

class Text(ABC):
    '''
    Абстрактный класс текста интерфейса
    '''
    @property
    @abstractmethod
    def text(self):
        pass

class Image(ABC):
    '''
    Абстрактный класс изображения интерфейса
    '''
    @property
    @abstractmethod
    def image(self):
        pass

class Help(ABC):
    '''
    Абстрактный класс справки интерфейса
    '''
    @property
    @abstractmethod
    def help(self):
        pass

class RussianText(Text):
    '''
    Русский текст
    '''
    def __init__(self):
        self._text = "Русский текст"
    @property
    def text(self):
        return self._text

class RussianImage(Image):
    '''
    Изобажение русского интерфейса
    '''
    def __init__(self):
        self._image = "Изобажение русского интерфейса"
    @property
    def image(self):
        return self._image

class RussianHelp(Help):
    '''
    Справка на русском языке
    '''
    def __init__(self):
        self._help = "Справка русского интерфейса"
    @property
    def help(self):
        return self._help

class EnglishText(Text):
    '''
    Английский текст
    '''
    def __init__(self):
        self._text = "Английский текст"
    @property
    def text(self):
        return self._text

class EnglishImage(Image):
    '''
    Изобажение английского интерфейса
    '''
    def __init__(self):
        self._image = "Изобажение английского интерфейса"
    @property
    def image(self):
        return self._image

class EnglishHelp(Help):
    '''
    Справка на английском языке
    '''
    def __init__(self):
        self._help = "Справка английского интерфейса"
    @property
    def help(self):
        return self._help

class FrenchText(Text):
    '''
    Французский текст
    '''
    def __init__(self):
        self._text = "Французский текст"
    @property
    def text(self):
        return self._text

class FrenchImage(Image):
    '''
    Изобажение французского интерфейса
    '''
    def __init__(self):
        self._image = "Изобажение французского интерфейса"
    @property
    def image(self):
        return self._image

class FrenchHelp(Help):
    '''
    Справка на французском языке
    '''
    def __init__(self):
        self._help = "Справка французского интерфейса"
    @property
    def help(self):
        return self._help

class RussianInterfaceFactory(InterfaceFactory):
    '''
    Фабрика русского интерфейса
    '''

    def create_text(self):
        return RussianText()

    def create_image(self):
        return RussianImage()

    def create_help(self):
        return RussianHelp()


class EnglishInterfaceFactory(InterfaceFactory):
    '''
    Фабрика английского интерфейса
    '''
    def create_text(self):
        return EnglishText()

    def create_image(self):
        return EnglishImage()

    def create_help(self):
        return EnglishHelp()

class FrenchInterfaceFactory(InterfaceFactory):
    '''
    Фабрика французского интерфейса
    '''
    def create_text(self):
        return FrenchText()

    def create_image(self):
        return FrenchImage()

    def create_help(self):
        return FrenchHelp()

concrete_interface = RussianInterfaceFactory()
