#06-024.py

import re

pattern = re.compile(r'[A-Z]{3}')
#ret = pattern.fullmatch('ABC123')
ret = pattern.fullmatch('ABC')
if ret:
    print('Matched : ' + ret.group())
else:
    print('NOT matched')
