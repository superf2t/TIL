#06-019.py

import re

pattern = re.compile(r'(\(\d{3}\)) (\d{3}-\d{4})')
ret = pattern.search('(031) 234-2345')
print(ret.group(1))
print(ret.group(2))
print(ret.groups())
print(ret.group(1, 2))
print(ret.start())
print(ret.end())
print(ret.span())
