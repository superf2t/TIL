#04-028.py

d = { 'a':97, 'b':98, 'c':99, 'd':100, 'e':101 }
print('dict =', d)
a = d.pop('f', 0)
b = d.pop('d', 0)
print('f =', a, 'd =', b, d)
a = d.popitem()
print(type(a), a, d.popitem(), d)
d.update([('b', 100), ('c', 101), ('d', 102)])
print(d)
a = dict.fromkeys( ['a', 'c'], 0) # classmethod   dict를 만드는 법 
print(type(a), a)







