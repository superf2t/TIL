#05-004.py

class Dog:
    kind = 'puddle'
    def __init__(self, name):
        self.name = name
    def printKind(self):
        print(self.kind, Dog.kind)
    def printName(self):
        print(self.name)
    def testlocal(self):
        a = 10
        print(a)
        print(locals())

d = Dog("Happy")
print(Dog.__dict__)
print(d.__dict__)
d.testlocal()
