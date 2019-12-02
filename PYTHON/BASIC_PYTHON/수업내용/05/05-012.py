#05-012.py
import pprint as pp

class Mammal:
    
    mCnt = 0
    oCnt = 0
    
    def __init__(self, sound):
        self.sound = sound
        Mammal.mCnt += 1
        
    @staticmethod
    def printCnt():
        print(Mammal.mCnt, ' Mammals.')
##    @classmethod
##    def printCnt(cls):
##        print(cls.mCnt, ' Mammals.')  # 같은 기능!
        
    def printSound(self):
        print(self.sound)
        

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



a = [Dog(), Cat(), Pig(), Dog(), Cat()]

for tmp in a:
    tmp.printSound()
    tmp.printCnt()
   
a[0].doSniff()
a[1].doJump()


