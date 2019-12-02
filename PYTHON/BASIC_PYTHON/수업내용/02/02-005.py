#02-005.py

def func1(pPK, *, pKi=10, pK):
    print(pPK, pKi, pK)
func1(10, pKi=20, pK=30)
func1(10, pK=30)
func1(pPK=10, pK=11, pKi=12)
print('============================')

def func2(pPK, pPKi=1, *, pK):
    print(pPK, pPKi, pK)
func2(10, pK=20)
func2(10, pPKi=20, pK=30)
func2(pPK=10, pPKi=20, pK=40)
func2(pK=10, pPKi=20, pPK=40)
func2(pPKi=20, pPK=10, pK=5)
print('============================')

def func3(pPK, pPKi=1, *pVP, pK):
    print(pPK, pPKi, pVP, pK)
func3(10, pPKi=20, pK=100)
func3(pPK=10, pPKi=30, pK=100)
func3(pPKi=10, pPK=30, pK=100)
func3(10, 20, pK=100)
func3(10, 20, 40, 50, pK=100)

