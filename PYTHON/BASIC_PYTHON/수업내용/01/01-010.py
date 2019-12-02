import sys

a = 0
print('a = 0', sys.getsizeof(a))
a = 123456789012345
print('a = 123456789012345', sys.getsizeof(a))
a = 2**1000
print('a = 2**1000', sys.getsizeof(a))
a = 3.14
print('a = 3.14', sys.getsizeof(a))
a = False
print('a = False', sys.getsizeof(a))
a = 'A'
print("a = 'A'", sys.getsizeof(a))
a = 'Happy'
print("a = 'Happy'", sys.getsizeof(a))
a = [1, 2, 3]
print('a = [1, 2, 3]', sys.getsizeof(a))
a = {1, 2, 3}
print('a = {1, 2, 3}', sys.getsizeof(a))
a = (1, 2, 3)
print('a = (1, 2, 3)', sys.getsizeof(a))
a = {'name':'soyoung', 'age':20}
print("a = {'name':'soyoung', 'age':20}", sys.getsizeof(a))
