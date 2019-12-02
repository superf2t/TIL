#05-007.py

import time

def mytimecheck(infunc):
    def outfunc(*a, **k):
        st = time.time()
        r = infunc(*a, **k)
        et = time.time()
        print(et-st)
        return r
    return outfunc

@mytimecheck
def myloop(s, e):
    sum = 0
    for i in range(s, e):
        sum += i
    return sum

print('sum = ', myloop(1, 10000000))
print('sum = ', myloop(1, 100000000))
