#02-003.py
'''
#Type 1
def func1 (pPKi1=10, pPKi2=20):
    return [pPKi1, pPKi2]

print(func1())
print(func1(5))
print(func1(5, 15))
print(func1(pPKi2=35))
print(func1(pPKi2=35, pPKi1=5))
#print(func1(10, 20, 30))

#Type 1
def func2 (pPK, pPKi=0):
    return [pPK, pPKi]

#print(func2()) --> Error
print(func2(10))
print(func2(10, 20))
print(func2(pPK=10))
#print(func2(pPKi=10)) --> Error
print(func2(pPKi=20, pPK=40))

#Type 1 (Wrong)
#def funcX(pPKi=10, pPK):
#    return [pPKi, pPK]

#Type 3
def func3(pPK, pPKi=0, *, pK):
    return [pPK, pPKi, pK]
print(func3(10, pK=30))
print(func3(10, 20, pK=30))
#print(func3(pK=10, 20, pPK=30))
print(func3(pPK=10, pPKi=20, pK=30))
print(func3(pPK=10, pK=30, pPKi=20))


#Type 3   
def func4(pPK, pPKi=0, *, pKi=10):
    return [pPK, pPKi, pKi]
#print(func4())
print(func4(20))
print(func4(10,30))
print(func4(10, pPKi=30))
print(func4(10, pKi=30, pPKi=20))


#Type 4
def func5 (pPKi=10, *pVP):
    return [ {pPKi}, [ x for x in pVP] ]

print(func5())
print(func5(pPKi=5))
print(func5(1,20,30,40,50))
print(func5(1, 'A', 'ABC', 3.5, 100))

#Type 4
def func6 (pPKi=10, *pVP, pK):
    return [ {pPKi}, pVP, {pK} ]

print(func6(10, 30, 40, 50, pK=20))
print(func6(10, pK=20))
print(func6(pK=20, pPKi=40))
#print(func6(10, 20, pK=20, pPKi=40))
print(func6(pK=100))


#Type 4
def func7(pPKi=10, *pVP, pKi=20, pK):
    return [ {pPKi}, pVP, {pKi}, pK ]

print(func7(pK=30))
print(func7(5, 20, 30, 40, pK=50))

#Type 5
def func8(*pVP, **pVK):   
    return [ pVP, pVK ]

print(func8(10, 20, 30, a=10, b=20))
print(func8(a=10, b=20))
print(func8(10, 20, 30))
print(func8())
#print(func8(a=10, b=20, 10, 20, 30))
'''
#Type 4, 5 (Wrong)
#def func9(**pVK, *pVP):
#    return [pVK, pVP]


