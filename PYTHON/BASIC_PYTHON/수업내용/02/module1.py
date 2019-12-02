#module1.py

##print(globals())

def add(a, b):
    print("I am add of module 1")
    ret = a + b
    return ret

def sub(a, b):
    print("I am sub of module 1")
    ret = a - b
    return ret


## 얘도 import 됨!!
a = 10
b = 20
print(a+b)
