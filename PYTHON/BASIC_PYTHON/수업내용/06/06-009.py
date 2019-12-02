#06-009.py

import re

pattern = re.compile(r'\d\w\W\s\w')
mc = re.search(pattern, '123_* ab')
if mc :
    print('{}~{}에 {}존재'.format(mc.start(), mc.end(), mc.group()))
else:
    print('문자열에 패턴이 존재하지 않음')




