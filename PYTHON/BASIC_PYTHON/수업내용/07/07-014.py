#07-014.py

import os, glob

os.chdir('C:\\MyPythonFiles')
print(glob.glob('.\\*'))
print(glob.glob('*.txt'))
print(glob.glob('TEMP\\[0-9]?.txt'))
print(glob.glob('temp\\[0-9]*.txt'))
print(glob.glob(os.path.abspath('.\\*.txt')))
a = glob.glob('*')
print(type(a), a)
a = glob.iglob('*')
print(type(a), a)
print(" ".join( x for x in a))

