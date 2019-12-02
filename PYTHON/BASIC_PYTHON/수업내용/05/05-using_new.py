import pprint as pp

##class ThatClass(object):
##    thatCnt = 0
##    
##    def __new__(cls):
##        ThatClass.thatCnt += 1
##        return super().__new__(cls)
##
##    def __init__(self):
##        self.a = "X"
##
##    def __str__(self):
##        return f'a = {self.a}'
##
##s = ThatClass()
##pp.pprint(ThatClass.__dict__)
##print(s.__dict__)


##class SomeClass_A(object):
##
##    def __new__(cls, *pVP):
##        if len(pVP) < 2: return None 
##        return super().__new__(cls)
##
##    def __init__(self, a, b):
##        self.a = a
##        self.b = b
##
##    def __str__(self):
##        return 'a = {}, b = {}'.format(self.a, self.b)
##
##s = SomeClass_A(10, 20)
##print(s)
##
##s = SomeClass_A(10)
##print(s)
##
##s = SomeClass_A(a=10, b=20)
##print(s)

##class SomeClass_B(object):
##
##    def __new__(cls, *pVP):
##        if len(pVP) > 2: return None 
##        return super().__new__(cls)
##
##    def __init__(self, a=None, b=None):     # 초기값 부여
##        self.a = a
##        self.b = b
##
##    def __str__(self):
##        return f'a = {self.a}, b = {self.b}'
##
##s = SomeClass_B(10, 20)
##print(s)
##
##s = SomeClass_B(10)
##print(s)
##
##s = SomeClass_B()
##print(s)
##
##s = SomeClass_B(10, 20, 30)
##print(s)
##
##s = SomeClass_B(a=10)
##print(s)


##class ThisClass(object):
##
##    def __new__(cls, *pVP, **pVK):
##        print(pVP, pVK)
##        if len(pVP) + len(pVK) != 3 : return None
##        return super(ThisClass, cls).__new__(cls)
##
##    def __init__(self, a, b, c):
##        self.a = a
##        self.b = b
##        self.c = c
##
##    def __str__(self):
##        return f'a = {self.a}, b = {self.b}, c = {self.c}'
##
##
##s = ThisClass(1, 2, 3)
##print(s)
##
##s = ThisClass(1, c=2, b=3)
##print(s)
##
##s = ThisClass(1, 2, 3, 4)
##print(s)


class WhatClass(object):
    
    def __new__(cls, **pVK):
        if len(pVK) > 3 : return None
        for x in pVK:
            if x not in ('a', 'b', 'c') : return None
        return super().__new__(cls)

    def __init__(self, a=None, b=None, c=None):
        self.a = a
        self.b = b
        self.c = c

    def __str__(self):
        return f'a = {self.a}, b = {self.b}, c = {self.c}'

w = WhatClass()
print(w)
w = WhatClass(a=10, x=20)
print(w)
w = WhatClass(b=10, a=5)
print(w)
w = WhatClass(c=10, a=5, b=20)
print(w)
w = WhatClass(10, 20)
print(w)

        
