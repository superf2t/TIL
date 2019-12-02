#07-005.py

import os

fileR = 'C:\\MyPythonFiles\\letter.txt'
fileW = 'C:\\MyPythonFiles\\letter_cp.txt'
fileW2 = 'C:\\MyPythonFiles\\letter_cp2.txt'

##forwrite = open(fileR, 'w')
##forwrite.write("Dear friend,\nHow are you?\nOptions:\nA\nB\nC\nD\nHidoyi!\n\n\nF\nG")
##forwrite.close()


## 1 : Options: ~ \n만 있는 문장까지만 추출해서 복사
if 0:
    forread = open(fileR, 'r')
    item = forread.readlines()
    forread.close()
    print(item)
    
    forcp = open(fileW, 'w')
    flag = False
    for i in item:
        if 'Options:' in i : flag = True
        elif i == '\n' : flag = False;  break    
        if flag == True :  forcp.write(i)

    forcp.close()

if 1:
    forread = open(fileR, 'r')
    item = forread.readlines()
    forread.close()

    forcp = open(fileW, 'w')


## 2 : Options: ~ \n만 있는 문장까지만 추출해서 복사 + 각 줄 앞에 문자 개수 나타내기
if 0:
    forread = open(fileR, 'r')
    item = forread.readlines()
    forread.close()

    forcp = open(fileW2, 'w')
    flag = False
    for i in item:
        if 'Options:' in i : flag = True
        elif i == '\n' : flag = False;  break    
        if flag == True :  forcp.write("["+str(len(i)-1)+"] "+i)

    forcp.close()
