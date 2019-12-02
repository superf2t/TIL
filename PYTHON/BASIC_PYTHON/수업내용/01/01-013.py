#01-013.py

def printBin(b):
    size = len(b)
    if (size < 32): b = '0' * (32-size) + b
    
    print('0b', end='_')    
    for a in range(7):
        c = a+1 
        print(b[a*4:c*4], end='_')
    print(b[28:32])
    
a = 0b_0011_0011_1100_1100_0011_0011_1100_1100
b = c = d = a

a |= (3<<24) | (1<<6) | (1<<0)
printBin(format(a, 'b'))
b ^= (3<<24) | (1<<6) | (1<<0)
printBin(format(a, 'b'))
c &= ~((3<<24) | (1<<6) | (1<<0))
printBin(format(a, 'b'))
printBin(format(d & (1<<5), 'b'))
