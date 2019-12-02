#06-023.py

import re

pattern = re.compile(r'[a-z]{2}')
ret = pattern.match('123abc123')
#ret = pattern.match('abcXde')
if ret:
    print('Matched : ' + ret.group())
else:
    print('NOT matched')
