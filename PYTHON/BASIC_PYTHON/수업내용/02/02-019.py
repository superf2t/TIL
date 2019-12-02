#02-019.py

print( (lambda x : x**2)(10))
power = lambda x: x**2
print (power(10))

print( (lambda x, y : x+y)(10, 20))
add = lambda x, y: x+y
print(add(10,20))

ex = lambda : 10
print(ex())

y = 20
ex = lambda x : x+y
print(ex(10))
