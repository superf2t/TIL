#06-010.py

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
            
printMatch(r'-[0-9]*-', ('--', '-1-', '-12-', '-123-', '-ab-', '-1a-') )
printMatch(r'-[a-z]+-', ('-c-', '-ab-', '-abc-', '-a12-', '-123-') )
printMatch(r'-[A-Z]?-', ('--', '-F-', '-A12-', '-AB-', '-123-'))
printMatch(r'-[0-9]{3}-', ('-123-', '-1234-', '-12-'))
printMatch(r'-[0-9]{3,4}-', ('-123-', '-1234-', '-12-', '-12345-'))
printMatch(r'-[0-9]{3,}-', ('-123-', '-1234-', '-12345-', '-12-'))
printMatch(r'-[0-9]{,4}-', ('-1-', '-12-', '-123-', '-1234-', '12345'))
