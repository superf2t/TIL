#05-008.py

class Dog:
    cnt = 0
    def __init__(self):
        Dog.cnt += 1
    @classmethod
    def printCnt(cls):
        print(str(cls.cnt) + ' dogs' )

Dog.printCnt()
a, b, c = Dog(), Dog(), Dog()
b.printCnt()
