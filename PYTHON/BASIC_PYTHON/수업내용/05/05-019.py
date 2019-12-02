#05-019.py

class SimpleA:
    value = 0
    def add (self, a, b):
        return a+b
    def sub (self, a, b):
        return a-b

s = SimpleA()
print(s.add(20, 10))
print(s.sub(20, 10))

fadd = lambda self, a, b : a+b
fsub = lambda self, a, b : a-b
members = {'value' : 0, 'add' : fadd, 'sub' : fsub }
SimpleB = type('B', (object,), members)
s = SimpleB()
print(s.add(20, 10))
print(s.sub(20, 10))

