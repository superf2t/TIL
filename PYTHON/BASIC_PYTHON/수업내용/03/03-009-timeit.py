#03-009-time.py
#https://nyu-cds.github.io/python-performance-tips/02-timing/

import timeit

n = 1000
def sumT1():
    sol = (n*(n+1))//2
    return sol
    #print(sol)
   
def sumT2():
    tot = 0
    for i in range(1, n+1):
        tot += i
    return tot
    #print(tot)

def sumT3():
    a = sum(range(1, n))
    return a
    #print(a)

print(timeit.timeit(sumT1, number=100000))
print(timeit.timeit(sumT2, number=100000))
print(timeit.timeit(sumT3, number=100000))


