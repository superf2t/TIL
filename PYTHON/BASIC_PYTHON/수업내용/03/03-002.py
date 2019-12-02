#03-002.py

def isthesame(a, b):
    print(id(a), id(b), end=', ')
    print('a==b', a == b, end=', ')
    print('a is b', a is b)
    
a, b = 10, 10
isthesame(a, b) ## interning 됨

a, b = -10, -10
isthesame(a, b) ## interning 안됨 : -5보다 작아서

a, b = 'happy', 'happy'
isthesame(a, b) ## interning 됨

a, b = 'so young', 'so young'
isthesame(a, b) ## interning 안됨 : 공백

a, b = (10, ), (10, )
isthesame(a, b) ## interning 안됨

a = 10
b = 10
isthesame(a, b)

a = -10
b = -10
isthesame(a, b)

a = 'happy'
b = 'happy'
isthesame(a, b)

a = 'so youngldaksjf lajofeij alkdsfo;iawh; lasd;fh a!!'
b = 'so youngldaksjf lajofeij alkdsfo;iawh; lasd;fh a!!'
isthesame(a, b)

a = (10, )
b = (10, )
isthesame(a, b) ## tuple 같은 경우에는 같지만... (밑에) list 같은 경우는 다름!
a = [10, 20, 30 ]
b = [10, 20, 30 ]
isthesame(a, b) ## list 같은 경우에는, mutable(가변이라는 뜻인가?)이기 때문에 다르다고 나옴!!

## 신기하게도 모두 다 같음!!
'''
# 문자열에 대해서 interning 하는 함수
# 파이썬 2에서는 built-in 함수인 intern() 사용
from sys import intern
a, b = intern('so young'), intern('so young')
isthesame(a, b)
'''
