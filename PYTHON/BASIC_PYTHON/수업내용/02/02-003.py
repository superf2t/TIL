#02-003.py

def func1 (pPK1=0, pPK2=0):
    return [pPK1, pPK2]
def func2 (pPK, pPKi=0):
    return [pPK, pPKi]
def func3 (pPKi=10, *pVP):
    return (pPKi, pVP)
#def funcX(pPKi=10, pPK):
#    return [pPKi, pPK]

print('func1 with 0 argument  :', func1())
print('func1 with 1 argument  :', func1(pPK1=10))
print('func1 with 1 argument  :', func1(pPK2=20))
print('func1 with 2 arguments :', func1(pPK2=10, pPK1=20))
print('func1 with 2 arguments :', func1(10, 20))
print('func2 with 1 argument  :', func2(10))
print('func2 with 2 argument  :', func2(10, 20))
print('func2 with 2 argument  :', func2(10, pPKi=20))
print('func2 with 2 argument  :', func2(pPK=30, pPKi=20))
print('func3 with 0 arguments :', func3())
print('func3 with 2 arguments :', func3(10, 20))
print('func3 with 3 arguments :', func3(10, 20, 30, 40))




