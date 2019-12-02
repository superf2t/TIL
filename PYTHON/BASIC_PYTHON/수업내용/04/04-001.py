#04-001.py
import copy
s = 'abcd'
print( 'c' in s, 'k' in s, 'z' not in s, 'd' not in s)
print( s + 'XYZ', s * 3, 3 * s )

#a = [  [] for x in range(3) ]
a = [[]]*3
print(a)
b = [1] * 5
print (a, b)
a[0].append(3)
##a[0].append(4)
b[1] = 3
b.append(4)
print (a, b)


