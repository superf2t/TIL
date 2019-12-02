#05-026answer.py

class Dog :
    def __init__(self, name, weight):
        self.name = name
        self.weight = weight
        
    def __add__(self, other):
        return self.weight + other.weight 

a = Dog('Happy', 15)
b = Dog('Joy', 10)
print(a+b)
