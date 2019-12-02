import sys

d = [1, 2, 3, 4,5,6,7,8,9,10]
print(sys.getsizeof(d), len(d))
del d[0:5]
print(d)
print(sys.getsizeof(d))
d.clear()
print(sys.getsizeof(d))

d = {}
for x in range(20):   
    print(sys.getsizeof(d))
    d[x] = x+1
    print(sys.getsizeof(d), len(d))

for x in range(20):
    print(sys.getsizeof(d), d.pop(x, 0))

d.clear()
print(sys.getsizeof(d))
