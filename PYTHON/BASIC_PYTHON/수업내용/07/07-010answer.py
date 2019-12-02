#07-010answer.py

import shelve
class A:
    def __init__(self, n1, n2):
        self.n1 = n1
        self.n2 = n2
    def printSum(self):
        print( (self.n1 + self.n2) )
        
myShelf = shelve.open('myobj')
myA = A(3, 6)
myShelf['myA'] = myA
myB = myShelf['myA']
myB.printSum()
