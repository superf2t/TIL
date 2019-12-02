#05-030.py

def printString(msg):
    if (len(msg) < 1) :
        raise IndexError('악!!!')
    print(msg)

printString('')
printString('abc')

