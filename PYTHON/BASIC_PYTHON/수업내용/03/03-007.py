#03-007.py

class A:
    pass

a = A()

class B:
    def func(self):
        pass

b = B()
b.func()

def func():
    pass

func()

a = 500
if a > 1000:
    print('large')
elif a < 100:
    print('small')
else:
    pass
