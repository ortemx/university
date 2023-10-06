'''
Паттерн «Абстрактная фабрика»
'''

from abc import ABC, abstractmethod


# Базовые классы интерфейса
class Text(ABC):
    '''
    Абстрактный класс текста интерфейса
    '''
    def __init__(self, text: str):
        self._text = text

    @abstractmethod
    def desc(self):
        pass


class Image(ABC):
    '''
    Абстрактный класс изображения интерфейса
    '''
    def __init__(self, image: str):
        self._image = image

    @abstractmethod
    def desc(self):
        pass


class Help(ABC):
    '''
    Абстрактный класс справки интерфейса
    '''
    def __init__(self, help: str):
        self._help = help
    @abstractmethod
    def desc(self):
        pass


# базовый класс фабрики интерфейса
class InterfaceFactory(ABC):
    '''
    Фабрика интерфейса
    '''
    @abstractmethod
    def create_text(self) -> Text:
        '''
        Создание текста
        '''

    @abstractmethod
    def create_image(self) -> Image:
        '''
        Создание изображения
        '''

    @abstractmethod
    def create_help(self) -> Help:
        '''
        Создание справки
        '''


# класс Клиента
class Client:
    '''
    Клиент
    '''
    def __init__(self, factory: InterfaceFactory):
        self._factory = factory
        self.text = None
        self.image = None
        self.help = None

    def run(self):
        text = self._factory.create_text()
        image = self._factory.create_image()
        help = self._factory.create_help()
        text.desc()
        image.desc()
        help.desc()



# производный класс русского интерфейса
class RussianText(Text):
    '''
    Русский текст
    '''
    def __init__(self):
        super().__init__("Русский текст")
    
    def desc(self):
        print("Создание русского текста")


class RussianImage(Image):
    '''
    Изобажение русского интерфейса
    '''
    def __init__(self):
        super().__init__("Изобажение русского интерфейса")

    def desc(self):
        print("Создание изображения русского интерфейса")


class RussianHelp(Help):
    '''
    Справка на русском языке
    '''
    def __init__(self):
        super().__init__("Справка русского интерфейса")

    def desc(self):
        print("Создание справки русского интерфейса")


# производный класс английского интерфейса
class EnglishText(Text):
    '''
    Английский текст
    '''
    def __init__(self):
        super().__init__("Английский текст")

    def desc(self):
        print("Создание английского текста")


class EnglishImage(Image):
    '''
    Изобажение английского интерфейса
    '''
    def __init__(self):
        super().__init__("Изобажение английского интерфейса")

    def desc(self):
        print("Создание изображения английского интерфейса")


class EnglishHelp(Help):
    '''
    Справка на английском языке
    '''
    def __init__(self):
        super().__init__("Справка английского интерфейса")
    def desc(self):
        print("Создание справки английского интерфейса")


# производный класс французского интерфейса
class FrenchText(Text):
    '''
    Французский текст
    '''
    def __init__(self):
        super().__init__("Французский текст")
    def desc(self):
        print("Создание французского текста")


class FrenchImage(Image):
    '''
    Изобажение французского интерфейса
    '''
    def __init__(self):
        super().__init__("Изобажение французского интерфейса")

    def desc(self):
        print("Создание изображения французского интерфейса")


class FrenchHelp(Help):
    '''
    Справка на французском языке
    '''
    def __init__(self):
        super().__init__("Справка французского интерфейса")
    def desc(self):
        print("Создание справки французского интерфейса")


# производный класс фабрики русского интерфейса
class RussianInterfaceFactory(InterfaceFactory):
    '''
    Фабрика русского интерфейса
    '''

    def create_text(self) -> Text:
        return RussianText()

    def create_image(self) -> Image:
        return RussianImage()

    def create_help(self) -> Help:
        return RussianHelp()


# производный класс фабрики английского интерфейса
class EnglishInterfaceFactory(InterfaceFactory):
    '''
    Фабрика английского интерфейса
    '''
    def create_text(self) -> Text:
        return EnglishText()

    def create_image(self) -> Image:
        return EnglishImage()

    def create_help(self) -> Help:
        return EnglishHelp()


# производный класс фабрики французского интерфейса
class FrenchInterfaceFactory(InterfaceFactory):
    '''
    Фабрика французского интерфейса
    '''
    def create_text(self) -> Text:
        return FrenchText()

    def create_image(self) -> Image:
        return FrenchImage()

    def create_help(self) -> Help:
        return FrenchHelp()


def chose_factory(language: str) -> InterfaceFactory:
    factory_dict = {
        "Ru": RussianInterfaceFactory,
        "En": EnglishInterfaceFactory,
        "Fr": FrenchInterfaceFactory
    }
    return factory_dict[language]()


interface = chose_factory("Ru")
client = Client(interface)
client.run()