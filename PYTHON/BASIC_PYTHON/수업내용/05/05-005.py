#05-005.py

name = 'Global variable'
class Dog:
    name = 'Jack'
    def __init__(self, name):
        self.name = name
    def printName(self):
        print(name)
    def testlocal(self):
        name = 'local variable'
        return name

a = Dog("Merry")
a.printName()
print(a.__class__)
print(a.testlocal())
print(a.name)
print(Dog.name)




