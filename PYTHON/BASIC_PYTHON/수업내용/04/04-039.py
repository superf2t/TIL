#04-039.py

a = [x*2 for x in range(1, 6)]  #iterable
g = (x*2 for x in range(1, 6))  #iterator
print(a)
print(g)

for i in range(5) : print(a[i], end=' ')
for i in range(5) : print(g[i], end=' ')
print()

print (next(a))
print (next(g))
c = iter(a)
print (next(c))




