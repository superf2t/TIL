#02-008.py

def plus(a, b):
    return a+b

def callFunc(f):
    print('id(f) =', id(f))
    return f(2, 3)

print('id(plus) =', id(plus))
print(callFunc(plus))
print(plus(2, 3))




