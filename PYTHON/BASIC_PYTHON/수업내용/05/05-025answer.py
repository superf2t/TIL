#05-025answer.py

class Dog :
    def __init__(self, name, weight):
        self.name = name
        self.weight = weight
    def __gt__(self, other):
        return self.weight > other.weight 

a = Dog('Happy', 5)
b = Dog('Joy', 10)
print(a>b)


'''
#05-025answer.py   (정렬, 출력 추가) 정렬은 __gt__로도 가능 

class Dog :
    def __init__(self, name, weight):
        self.name = name
        self.weight = weight
    def __lt__(self, other):
        return self.weight < other.weight
    def __repr__(self):
        return self.name + "_" + str(self.weight)

a = Dog('Happy', 5)
b = Dog('Joy', 10)
c = Dog('Merry', 3)
doglist = [a, b, c]
doglist.sort(reverse=True)
for x in doglist:
    print(x)
    
'''
