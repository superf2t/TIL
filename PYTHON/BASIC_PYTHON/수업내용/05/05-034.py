#05-034.py

def mygen():
    yield 1
    yield 2
    yield 3

for i in mygen():
    print(i)

    
