#06-011answer.py

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

pstr =r'-[1-9]+[0-9]*-'
data = ('-0-', '-1-', '-12-', '-321-', '-100-', '-01-', '-1a-', '-0010-')
printMatch(pstr, data)



