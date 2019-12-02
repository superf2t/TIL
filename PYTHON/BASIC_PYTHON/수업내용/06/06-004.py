#06-004.py

import re

def isPhoneNumber(num):
    if re.search(r'^01[0-26-9]-[0-9]{3,4}-[0-9]{4}$', num) :
        return True
    return False

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
