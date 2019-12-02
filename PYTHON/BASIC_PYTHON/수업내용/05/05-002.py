#05-002.py

class Mammal:
    def __init__(self, name):
        self.name = name         
    def printName(self):
        print("My name is", self.name)

m = Mammal('Happy')
m.printName()


