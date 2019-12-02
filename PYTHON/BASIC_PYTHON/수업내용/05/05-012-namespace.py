#05-012-namespace.py
# __init__  : need to call

class Mammal:
    mCnt = 0
    oCnt = 0
    def __new__(cls):
        cls.hidoyi = 19
        cls.age = 1
        print("Mammal new : ", cls.__name__)
        return super().__new__(cls) 
    def __init__(self):
        print("Mammal init ", self.__class__)
        Mammal.mCnt += 1
    @staticmethod
    def printCnt():
        print(Mammal.mCnt, ' Mammals.')

            
class Dog(Mammal):
    def __new__(cls):
        print("Dog new ")
        return super().__new__(cls)
    def __init__(self):
        Mammal.__init__(self)
        Dog.oCnt += 1  # Dog.oCnt = Dog.oCnt + 1
        #print(id(Mammal.oCnt), id(Dog.oCnt))
    def printCnt(self):
        print(Dog.oCnt, ' Dogs.')


class Cat(Mammal):
    def __new__(cls):
        print("Cat new ")
        return super().__new__(cls)   
    def __init__(self):
        Mammal.__init__(self)
        Cat.oCnt += 1
        #print(id(Mammal.oCnt), id(Cat.oCnt))
    def printCnt(self):
        print(Cat.oCnt, ' Cats.')

        
class Pig(Mammal):
    def __new__(cls):
        print("Pig new ")
        return super().__new__(cls)
    def __init__(self):
        Mammal.__init__(self)
        #super().__init__()
        Pig.oCnt += 1
       # print(id(Mammal.oCnt), id(Pig.oCnt))
    def printCnt(self):
        print(Pig.oCnt, ' Pigs.')

        
def printMOCnt (name, ns) :
    try :
        if ns['mCnt'] : print(name, 'mCnt', ns['mCnt'])
    except KeyError: pass

    if ns['oCnt'] : print(name,'oCnt', ns['oCnt'])

    

##m = Mammal()
##m.printCnt()

a = [Dog(), Cat(), Pig()]
Mammal.printCnt()
a[0].printCnt()

print('------')
print(a.__class__)
print('------')

##for x in [Mammal, Dog, Cat, Pig]:
##    print(x.__dict__)
import pprint
for x in [Mammal, Dog, Cat, Pig]:
    pprint.pprint(x.__dict__)

