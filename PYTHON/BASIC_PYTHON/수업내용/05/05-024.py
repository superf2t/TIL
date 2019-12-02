#05-024.py

class Dog :
    def __init__(self, name, weight):
        self.name = name
        self.weight = weight
    def __str__(self):
        return 'name is {}, weight is {}'.format(self.name, self.weight)

a = Dog('Happy', 5)
b = Dog('Joy', 10)
print(a)
print(str(b))

