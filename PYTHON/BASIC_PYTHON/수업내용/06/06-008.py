#06-008.py

import re
pattern = re.compile(r'[0-9][abc][^c-z]')
mc = re.search(pattern, '123abcd')
if mc :
    print('{}~{}에 {}존재'.format(mc.start(), mc.end(), mc.group()))
else:
    print('문자열에 패턴이 존재하지 않음')
