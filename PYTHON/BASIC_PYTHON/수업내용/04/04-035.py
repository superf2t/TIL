#04-035.py

a = [65, 66, 67, 68]
b = ('A', 'B', 'C', 'D')
ab = zip(a, b)
print(type(ab))
for x in ab:
    print(type(x), x)
ab = dict(zip(a, b))
print(ab)
