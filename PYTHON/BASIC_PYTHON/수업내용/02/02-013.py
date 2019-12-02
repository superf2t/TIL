#02-013.py


def changeGlobalA():
    global a
    a = 10
    print(a)

a = 100
print(a)
changeGlobalA()
print(a)


