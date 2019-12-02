#04-037.py

a = [ x*2 for x in range(6) ]
print(type(a), a)

a = [ 100, 50, 200, 100, 300 ]
tot = sum(a)
b = [ int(x/tot*100) for x in a ]
print(b)

a = 'sweet watermelon'
V = ['a', 'e', 'i', 'o', 'u']
b = ''.join( [ x for x in a if x not in V ] )
print(b)

a = [ -1, 'a', '1', 1, 2, 'red', 3.4, True ]
b = [ x*x for x in a if type(x) == int ]
print(b)

a = [ 'x', 'y', 'z' ]
b = [ ( n, m ) for n in a for m in range(3) ]
print(b)

M = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ]
b = [ col for row in M for col in row ]
print(b)


