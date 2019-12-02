#07-012.py

import os
os.chdir('C:\\MyPythonFiles')
print('1:', os.listdir())
os.makedirs('.\\dirs\\a\\b', exist_ok=True)
print('2:', os.listdir())
print('3:', os.listdir('.\\dirs'), os.listdir('.\\dirs\\a'))
if os.access('MYDIR', os.F_OK) and not os.access('TEMP', os.F_OK):
    os.rename('MYDIR', 'TEMP')
else :
    print("MYDIR doesn't exist")

os.removedirs('.\dirs\\a\\b')
print('4:', os.listdir())

