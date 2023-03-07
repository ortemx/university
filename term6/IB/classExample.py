class MyClass(object):
    __name = ""
    name = ""
    __age = 0
    
    def __init__(self, name1, name2, age):
        self.__name = name1
        self.name = name2
        self.__age = age
  
    @property
    def age(self):
        return self.__age
    
    @property
    def name1(this):
        return this.__name
    
    @property
    def name2(self):
        return self.name
    
    
myclass = MyClass("a", "b", 10)
print(myclass.age, myclass.name1, myclass.name2)