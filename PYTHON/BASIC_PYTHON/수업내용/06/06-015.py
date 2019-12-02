#06-015.py

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

data = ('birthday : 1990-12-12', '93-6-30', 'a-b-c')
printMatch(r'\b[0-9]+-[0-9]+-[0-9]+\b',  data)

data = ('A : 123-123-1234', '123-1234-1234', 'C : 12-34-5678')
printMatch(r'\b[0-9]{3}-[0-9]{3,4}-[0-9]{4}\b',  data)

data = ('phone : 010-123-1234', '018-1234-1234', '001-567-9876')
printMatch(r'\b01[0126-9]-\d{3,4}-\d{4}\b',  data)

data = ('phone : 010-123-1234', '018-1234-1234', '001-567-9876')
printMatch(r'\b01[0126-9]-[0-9]{3,4}-[0-9]{4}\b',  data)
