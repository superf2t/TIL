#05-006.py

import pprint as pp

class Dog:
    kind = 'puddle'
    def __init__(self, name):
        self.name = name
    def printKind(self):
        print(self.kind, Dog.kind)
    def printName(self):
        print(self.name)

a = Dog("Merry")
b = Dog("Happy")

Dog.owner = 'Julie'
print(a.owner, b.owner, Dog.owner)
a.snack = ['cheese', 'beef']
print(a.snack)
#print(b.snack)



