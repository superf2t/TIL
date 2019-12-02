#04-041.py

a = ('A', 'B', 'C', 'D', 'E', 'F', 'G' )
print(enumerate(a))
for idx, value in enumerate(a): print (idx, value)
print(list(enumerate(a)))
b = { idx : value for idx, value in enumerate(a, start=65) }
print(b, 'b[65] =', b[65])
b = { value : idx for idx, value in enumerate(a, start=65) }
print(b, "b['A'] =", b['A'])

