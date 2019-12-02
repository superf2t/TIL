#06-007.py

import re
pattern = re.compile(r'abc')
mc = re.search(pattern, '123abcdabc')
if mc :
    print('{}~{}에 {}존재'.format(mc.start(), mc.end(), mc.group()))
else:
    print('문자열에 패턴이 존재하지 않음')


#mc = pattern.search('123abcd')
#mc = re.search(r'abc', '123abcd')
