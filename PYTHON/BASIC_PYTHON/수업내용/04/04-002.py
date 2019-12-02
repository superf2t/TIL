#04-002.py

a = (1, 2, 'go', 4, 5, 6, 7, 8, 9, 10)
print(type(a), a)
print(type(a[0]), a[0])
print(type(a[2]), a[2])
b = a[2:5]
print(type(b), b)
print(a[3:])
print(a[:5])
print(a[::3])
print(a[1:-2])
print(a[-4:-1])


a = [1, 2, 'go', 4, 5, 6, 7, 8, 9, 10]
b = a[2:5]
b[1] = 'go'
print(type(b), b)
print(a)

a = [1, 2, [10, 20, 30], 4, 5, 6, 7, 8, 9, 10]
b = a[2:5]
print(type(b), b)
print(type(b[0]), b[0])
b[0][0] = 100
print(a)

