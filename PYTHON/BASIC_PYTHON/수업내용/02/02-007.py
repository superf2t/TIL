#02-007.py

def func(**pVK):
    print(type(pVK))
    for x in pVK.items():
        print(type(x), x, x[0], x[1])

func(a=10, b=20, c='Hello')

