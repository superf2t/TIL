#05-001.py

class Mammal(object, metaclass=type):
    pass

m = Mammal()
print(dir(m), hash(m), m, sep='\n')
print(dir(Mammal), hash(Mammal), Mammal, sep='\n')



print(dir(object), hash(object), object, sep='\n')


globals()
