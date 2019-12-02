#04-018.py

a = bytes()
b = bytes(5)
c = bytes(b'12345')
d = bytes(range(49, 54))
e = bytes('12345', encoding='utf-8')
print (a, b, c, d, e, sep='\n')

x = b'ABCDE'
print(x[0], x[1], x[2])
print(x[0:3], x[2:-1], x[::2])
print(b'123' + x)
print(b'\x01' * 5)
print(b'BC' in x, b'ABCDE' is x)
print(id(x), x)
x += b'ABC'
print(id(x), x)

