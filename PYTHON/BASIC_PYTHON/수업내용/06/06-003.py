#06-003.py

pno = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1]

def isPhoneNumber(num):  
    if len(num)<12 or len(num)>13 : return False
    grp = num.split('-')
    if (len(grp) != 3) : return False
    if len(grp[0]) != 3 or grp[0].isdecimal() == False : return False
    if grp[0][0:2] != '01' : return False
    if pno[int(grp[0][2])] == 0 : return False
    if len(grp[1]) < 3 or len(grp[1])>4 or grp[1].isdecimal() == False : return False
    if len(grp[2]) != 4 or grp[2].isdecimal() == False : return False
    return True    

def check(num):
    msg = ('Wrong number', 'Correct number')
    if isPhoneNumber(num) : print(num, msg[1])
    else : print(num, msg[0])
    
check('010-456-7892')
check('010-2345-1234')
check('013-123-1231')
check('012 1234 1234')
check('016-12-1234')
check('TEL: 012-123-1234')
check('017-123-1234!')
    
