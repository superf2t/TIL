#06-022.py

import re

pattern = re.compile(r'[a-z]{2}')
ret = pattern.search('123abc123')
#ret = pattern.search('abcXde')
if ret:
    print('Matched : ' + ret.group())
else:
    print('NOT matched')
