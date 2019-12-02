#05-013.py

class Mammal:
    mCnt = 0
    oCnt = 0
    def __init__(self, sound):
        self.sound = sound
        Mammal.mCnt += 1
        
    def printSound(self):
        print(self.sound)
        
    @staticmethod
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
    def callMammalMethod(self):
        Mammal.printCnt()
        self.printCnt()
        super().printSound()
        self.printSound()
        
    def __init__(self):
        Mammal.__init__(self, 'oink')
        Pig.oCnt += 1
        
    def printCnt(self):
        print(Pig.oCnt, ' Pigs.')

      
a = Pig()
a.callMammalMethod()
print(a.__class__)
#print(a.__class__, Pig.__module__)



