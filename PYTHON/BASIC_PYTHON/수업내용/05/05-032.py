#05-032.py

class ListEmptyError(Exception):
    def __init__(self, msg):
        self.msg = msg
    def __str__(self):
        return self.msg

class A:
    alist = list()
    def printList(self):
        if (len(self.alist) == 0):
            raise ListEmptyError('List is Empty!')
        print(self.alist)
    def setList(self, data):
        self.alist = data

try:
    a = A()
##    a.setList([1, 2, 3])
    a.printList()
except ListEmptyError as emsg:
    print('ListEmptyError:', emsg)

a = A()
a.printList()
print('DONE')
