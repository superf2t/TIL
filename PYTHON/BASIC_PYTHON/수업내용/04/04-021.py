a = bytearray()
b = bytearray(5)
c = bytearray(b'abcde')
d = bytearray(range(97, 102))
e = bytearray('abcde', encoding='utf-8')
print(a, b, c, d, e, sep='\n')

print(id(c), c)
c[0] = 65
c[1:5] = b'BCDE'
del c[2:4]
print(id(c), c)
c += b'XY'
c *= 2
print(id(c), c)


