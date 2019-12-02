#06-016answer.py

import re

def printMatch(pstr, data):
    print(pstr)
    print(data)
    pattern = re.compile(pstr)
    for x in data :
        mc = re.search(pattern, x)
        if mc :
            print('{}~{}에 {}존재'.format(mc.start(), mc.end(), mc.group()))
        else:
            print('NO Match')

data = ('1990-09-12', '2020-12-31', '2099-10-32', '89-01-08')
printMatch(r'\b(19|20)[0-9]{2}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[01])\b',  data)           
