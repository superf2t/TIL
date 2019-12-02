#02-001.py

def add(a, b):
    c = a + b
    print('%d + %d = %d' %(a, b, c))
    return None

add(10,20)

def add_ret(a, b):
    c = a + b
    return c

r = add_ret(10,20)
print('%d + %d = %d' %(10, 20, r))

