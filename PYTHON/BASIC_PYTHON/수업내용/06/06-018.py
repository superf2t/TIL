#06-018.py

import re

ret = re.sub('[a-z]+', 'X',  'abc1de2fg3hij')
print(ret)
ret = re.split(r'[0-9]', 'abc18de2fg3hij')
print(ret)
