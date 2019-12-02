def myhex(x) :
    return hex(x)[2:]
    
a = ''.join(map(myhex, [ x for x in range(65, 70)] ))
b = bytes.fromhex(a)
#b = bytes.fromhex('41 42   43  44 45')
c = b.hex()
print(a, b, c, d, sep='\n')
a = b.decode(encoding='utf8')
print(a)
b = b'www.willtek.com'
table=b'..........................................................................................0123456ABC\
DEFGHIJKLMNOPQRSTUVWXYZ3456789....................\
..........................................................................................................'
print(len(table))
x = b.translate(None, delete=b'wcome')
y = b.translate(table, delete=b'wcome')
print(x, y)
b = b'abcababcd'
x = b.find(b'aba')
y = b.find(b'aba', 5)
print(x, y)
b = b'abcababcd'
x = b.index(b'aba')
#y = b.index(b'aba', 5)
print(x)

