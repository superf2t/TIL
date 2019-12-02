#07-002.py

import os

os.chdir('C:\\MyPythonFiles\\TextFiles')
print(os.getcwd())
#filename = 'test.txt'
filename = 'C:\\MyPythonFiles\\TextFiles\\test.txt'
print(os.path.getsize(filename))
print(os.path.exists(filename))
print(os.path.isdir(filename))
print(os.path.isfile(filename))
