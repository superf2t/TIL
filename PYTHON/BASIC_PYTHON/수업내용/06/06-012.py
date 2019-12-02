#06-012.py

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
            
printMatch(r'-a..o-', ('-a12o-', '-abco-', '-aBo-', '-a123o-') )
printMatch(r'^[a-z]+', ('a12', 'kbs', '123a', 'KBstar') )
printMatch(r'[0-9]+$', ('ab123', 'UP3', 'a12b'))
printMatch(r'abc|123', ('abcdef', '-1234-', '12431', 'axybz'))

pattern = re.compile('.abc')
ret = pattern.search('\nabc')
print('search .abc ', ret)

pattern = re.compile('.abc', re.S)
ret = pattern.search('\nabc')
print('search .abc ', ret)
