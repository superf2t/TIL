#04-019.py

a = list(b'0123456789')
b = tuple(b'abcde')
c = set(b'abcde')
d = { i:x for i, x in enumerate(b'ABCDE') }
print(a, b, c, sep='\n')
for x in d.items():
    print(x, end=' ')


