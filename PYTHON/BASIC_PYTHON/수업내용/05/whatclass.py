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
