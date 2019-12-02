#02-010.py

def myCals(a, b):
    return a+b, a-b, a*b, a/b

ret = myCals(20, 5)
plus, minus, multi, divi = ret
print(plus, minus, multi, divi)

print(type(ret), ret)
