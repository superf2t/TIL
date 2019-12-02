#05-014.py

class Mammal:
    mCnt = 0
    oCnt = 0
    def __init__(self, sound):
        self.sound = sound
        Mammal.mCnt += 1
    def printSound(self):
        print(self.sound)
    def printCnt():
        print(Mammal.mCnt, ' Mammals.')
            
class Dog(Mammal):
    def __init__(self):
        Mammal.__init__(self, 'bowwow')
        Dog.oCnt += 1
    def printCnt(self):
        print(Dog.oCnt,  ' Dogs.')
    def doSniff(self):
        print('Dog is sniffing.')
        
class Cat(Mammal):
    def __init__(self):
        Mammal.__init__(self, 'meow')
        Cat.oCnt += 1
    def printCnt(self):
        print(Cat.oCnt, ' Cats.')
    def doJump(self):
        print('Cat is jumping.')
        
class Pig(Mammal):
    def __init__(self):
        Mammal.__init__(self, 'oink')
        Pig.oCnt += 1
    def printCnt(self):
        print(Pig.oCnt, ' Pigs.')
    def callMammalMethod(self):
        Mammal.printCnt()
        super().printSound()
        self.printSound()
        
a = (Dog(), Cat(), Pig())
print('a[0] is a Dog or Cat', isinstance(a[0], (Dog, Cat)))
print('a[1] is a Dog', isinstance(a[1], Dog))
print('Dog is a Mammal', issubclass(Dog, Mammal))
print('Cat is a Mammal', issubclass(Cat, Mammal))
print('Dog is an object', issubclass(Dog, object))
print('Mammal is an object', issubclass(Mammal, object))
print(Dog.__dict__)
print(a[0].__dict__)
print(Dog.__bases__)
print(Mammal.__bases__)
