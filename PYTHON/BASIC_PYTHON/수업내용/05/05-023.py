#05-023.py

class AInt(int):
    def __add__(self, num):
        return self.real + num

class MyInt(int):
    def __add__(self, num):
        return 'ANSWER: ' + str(self.real + num)

a = AInt(10)
print(type(a+5), a+5)

m = MyInt(10)
print(type(m+5), m+5)
