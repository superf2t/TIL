#07-005answer.py

import os

fileR = 'C:\\MyPythonFiles\\letter.txt'
fileW = 'C:\\MyPythonFiles\\letter_cp.txt'
if os.path.exists(fileR) :
    myfileR = open(fileR)
    mycontents = myfileR.readlines()
    myfileR.close()
    
    myfileW = open(fileW, 'w')
    for myline in mycontents :
        myfileW.write(myline)
    myfileW.close()    
else :
    print(fileR + ' doesn\'t exist')

