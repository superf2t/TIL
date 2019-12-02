#07-001.py

import os

os.chdir('C:\\MyPythonFiles\\TextFiles\\A')
print(os.getcwd())
print(os.path.abspath('..\\B'))
print(os.path.isabs('.'))
print(os.path.relpath('C:\\MyPythonScript'))
print(os.path.relpath('C:\\MyPythonScript', 'C:\\'))
file = 'C:\\MyPythonFiles\\TextFiles\\test.txt'
print(os.path.basename(file))
print(os.path.dirname(file))
print(file.split(os.path.sep))

