#04-015.py

def printL(a):
    print(len(a), a)
    
printL('AB C\n\nAB\r\rAB\r\n'.splitlines())
printL('AB C\n\nAB\r\rAB\r\n'.splitlines(keepends=True))
printL('AB C\n\nAB\r\rAB\r\n'.split('\n'))
printL('A\n'.split('\n'))
printL('A\n'.splitlines())
print(len('ABC'), 'ABC'.splitlines('\n'))
print(''.split('\n'), ''.splitlines())


