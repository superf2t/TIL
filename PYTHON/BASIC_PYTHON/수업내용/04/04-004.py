#04-004.py

print(hash(10), hash(10.0), 10 == 10.0)
print(hash(True), hash(1), True == 1)

a = 'Happy'
b = str('Happy')
print(hash(a), hash(b), a == b)
print(id(a), id(b), a is b)

a = (1, 2, 3, 4)
b = (1, 2, 3, 4)
print(hash(a), hash(b), a == b)
print(id(a), id(b), a is b)

print('=======================')

## set
a = {1, True, 1.0}
b = {True, 1.0, 1}
c = {1.0, True, 1}
print(a, b, c)
## set {  } : 중복된 값을 안 넣음!
   
## dictionary
d = {1: 'abc', True : 'def', 1.0 : 'hidoyi'}
print(d)
## 같은 key 값이 들어오면 갱신!! (없던 key 값이 들어오면 새로 만듦)
