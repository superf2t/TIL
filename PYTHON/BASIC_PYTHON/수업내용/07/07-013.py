#07-013.py

import sys

backup = sys.stdout
sys.stdout = open('out.dat', 'w')
print(sys.argv)
#print(sys.modules)
print(sys.path)
print(sys.copyright, sys.version)
print(sys.prefix, sys.executable)
sys.stdout = backup
sys.stdin = open('in.dat', 'r')
data = input("input message from 'in.data'")
print("\n" + data)

