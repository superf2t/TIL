#05-006_detail.py

import pprint as pp

class Dog:
    kind = 'puddle'
    def __init__(self, name):
        self.name = name
    def printKind(self):
        print(self.kind, Dog.kind)
    def printName(self):
        print(self.name)

#pp.pprint(globals())
a = Dog("Merry")
b = Dog("Happy")
#pp.pprint(globals())

pp.pprint(Dog.__dict__)
del Dog.kind
Dog.owner = 'Julie'
pp.pprint(Dog.__dict__)
print(a.owner, b.owner, Dog.owner)
print(dir(Dog))
print(a.__dict__)
a.snack = ['cheese', 'beef']
print('=========')
a.printSnack = lambda a : print(a.snack)
a.printSnack(a)
print(a.snack)
print(a.__dict__)
print(b.__dict__)
#print(b.snack)



