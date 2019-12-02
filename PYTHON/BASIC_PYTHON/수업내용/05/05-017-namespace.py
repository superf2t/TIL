#05-017-namespace.py
import pprint as pp

class Mammal:

    # special method 이므로   @를 안 붙여요
    
    def __new__(cls):
        print('Mammal_new : ', cls)
        cls.M = 'mammal'
        return super().__new__(cls)
        
    def __init__(self):
        self.mammal = "HEHE"
        print('Mammal__init__()')




        
class Horse(Mammal):
    
    def __new__(cls):
        print('Horse_new : ', cls)
        return super().__new__(cls)
        
    def __init__(self):
        self.horse = "HOHO"
        print('Horse__init__before()')
        super().__init__()
        print('Horse__init__after()')

    def printMe(self):
        print("I am a Horse!!")





class Ass(Mammal):
    
    def __new__(cls):
        print('Ass_new : ', cls)
        return super().__new__(cls)
        
    def __init__(self):
        self.ass = "HAHA"
        print('Ass__init__before()')
        super().__init__()
        print('Ass__init__after()')

    def printMe(self):
        print("I am a Ass!!")




        
class Mule (Horse, Ass):
    
    def __new__(cls):
        print('Mule_new : ', cls)
        return super().__new__(cls)
        
    def __init__(self):
        print('Mule__init__before()')
        super().__init__()
        print('Mule__init__after()')

    def printBase(self):
        super().printMe()

     
m = Mule()
pp.pprint(Mule.__dict__)
print(m.__dict__)
pp.pprint(Mule.__mro__)   
m.printBase()

h = Horse()
pp.pprint(Horse.__dict__)
print(h.__dict__)


