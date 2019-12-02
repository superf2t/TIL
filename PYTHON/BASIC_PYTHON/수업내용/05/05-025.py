#05-025.py

class Dog :
    def __init__(self, name, weight):
        self.name = name
        self.weight = weight
    def __gt__(self, comp):
        return self.weight > comp.weight and "Haiya~~" or "Neomuhae!!!"
    def __ge__(self, comp):
        return self.weight >= comp.weight and "Haiya~~" or "eomuhae!!!"
    def __str__(self):
        return f'{self.name} - {self.weight}'

    
a = Dog('Happy', 5)
b = Dog('aJoy', 10)

print(a>b)  # 몸무게 비교!
print(a<=b)

print(a)
print(b)

c = [a, b]
print(*c)
