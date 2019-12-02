#05-017.py

class Mammal:
    def __init__(self):
        print('Mammal__init__()')
        
class Horse(Mammal):
    def __init__(self):
        super().__init__()
        print('Horse__init__()')

class Ass(Mammal):
    def __init__(self):
        super().__init__()
        print('Ass__init__()')
        
class Mule (Horse, Ass):
    def __init__(self):
        super().__init__()
        print('Mule__init__()')

m = Mule()
