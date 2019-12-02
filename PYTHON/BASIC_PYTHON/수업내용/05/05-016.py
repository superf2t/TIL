#05-016.py

class Mammal:
    def __init__(self):
        print('Mammal__init__()')
        
class Horse(Mammal):
    def __init__(self):
        Mammal.__init__(self)
        print('Horse__init__()')

class Ass(Mammal):
    def __init__(self):
        Mammal.__init__(self)
        print('Ass__init__()')
        
class Mule (Horse, Ass):
    def __init__(self):
        Horse.__init__(self)
        Ass.__init__(self)
        print('Mule__init__()')

m = Mule()
