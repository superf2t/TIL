#06-017.py

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

data = ('sososo', 'sosososo', 'sososososo', 'soso')
printMatch(r'(so){3,5}', data)

data = ('sososo', 'sosososo', 'sososososo', 'soso')
printMatch(r'(so){3,5}?', data)

data = ('sasasa', 'sososo', 'sasosa', 'sososososo', 'sasasasaso', 'soso')
printMatch(r'(sa|so){3}?', data)

data = ('1', '12', '1234', '12ab34', '12 34')
printMatch(r'^\d+$', data)
