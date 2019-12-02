#06-029answer.py

import re

def idcheck(id):
    pattern = re.compile(r'(?P<front>[0-9]{6})-([0-9]{7})')
    ret = pattern.fullmatch(id)
    if ret :
        return ret.group('front')+'-' +'*'*7
    return id + ' is NOT an id'

print(idcheck('881103-1231233'))
print(idcheck('Julie Yoon'))
print(idcheck('1990-12-28'))


