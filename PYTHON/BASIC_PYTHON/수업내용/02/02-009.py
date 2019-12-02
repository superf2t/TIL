#02-009.py

def getAddSub(a, b):
    c = a + b
    d = a - b
    return c, d

a = 30
b = 20
add, sub = getAddSub(a, b)
print('%d + %d = %d' %(a, b, add))
print('%d - %d = %d' %(a, b, sub))


