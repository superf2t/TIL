#05-021.py

from abc import *

class Mammal(metaclass=ABCMeta):
    tName = '동물종류'
    
    def printType(self):
        print(Mammal.tName)

    @abstractmethod
    def printSound(self):
        pass

class Dog(Mammal):
    def __init__(self, sound):
        Mammal.tName = 'Dog'
        self.sound = sound

    def printSound(self):
        print(self.sound)
        
if __name__ == '__main__' :
    #m = Mammal()
    m = Dog("Bowwow")
    m.printType()
    m.printSound()
