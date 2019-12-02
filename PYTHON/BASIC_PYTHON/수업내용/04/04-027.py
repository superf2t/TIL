#04-027.py

d = {'0':48, '1':49, '2':50}
d['3'] = 52
print(d, '1=', d['1'])
d.setdefault('2', 'two')
d.setdefault('4', 52)
del d['3']
for x in d: print(x, end=' ')
print()
for x in d.items():
    k, v = x
    print(x, k, v)
print(d.keys(), list(d.keys()), sep='\n')
print(d.values(), list(d.values()), sep='\n')
print('4 = ', d.get('4', 0))
print('5 = ', d.get('5', 0))



