#06-016.py

import re

def printMatch(pstr, data):
    print(pstr)
    print(data)
    pattern = re.compile(pstr)
    for x in data :
        mc = re.search(pattern, x)
        if mc :
            print('{}~{}에 {}존재'.format(mc.start(), mc.end(), mc.group()))
            print("따로 출력(연 / 월 / 일) : ", mc.group(1), "/", mc.group(2), "/", mc.group(3))
            print(f'year = {mc.group(1)}, month = {mc.group(2)}, day = {mc.group(3)}')
        else:
            print('NO Match')

data = ('1990-09-12', '2020-12-31', '2099-10-32', '89-01-08', '1999-05-33')
printMatch(r'\b((?:19|20)\d{2})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])\b',  data)         #XXXXXXX 에 패턴을 작성한다 
