#05-031.py

def printString(msg):
    if (len(msg) < 1) :
        raise IndexError('msg is empty')
    print(str)

def testPrint():
    try:
        printString('')
        printString('abc')
    except:
        print('Exception occurs!!')
##        raise

testPrint()
