#05-009.py

class Dog:
    cnt = 0
    def __init__(self):
        Dog.cnt += 1        
    @staticmethod
    def printCnt():
        print(str(Dog.cnt) + ' dogs')
        
Dog.printCnt()
a, b, c = Dog(), Dog(), Dog()
b.printCnt()

