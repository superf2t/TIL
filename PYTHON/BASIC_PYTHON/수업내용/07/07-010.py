#07-010.py

import shelve

class A:
    def __init__(self, a, b):
        self.num1 = a
        self.num2 = b

    def printSum(self):
        print(self.num1 + self.num2)

# 이곳에 shelve 코드를 작성한다        



with shelve.open("myobj") as myShelf:
    a = A(20, 50)
    myShelf["myA"] = a
    myB = myShelf["myA"]
    myB.printSum()
