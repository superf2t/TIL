#06-025.py

import re
pattern = re.compile(r'.*')#, re.DOTALL)
ret = re.search(pattern, 'Good\nBetter')
#ret = re.search(r'.*', 'Good\nBetter', re.DOTALL)
print(ret.group())

ret = re.finditer(r'abc', 'abcABCAbC', re.IGNORECASE)
for r in ret:
    print(r.group())

print('Without options!')
pattern = re.compile(r'.*')
ret = re.search(pattern, 'Good\nBetter')
#ret = re.search(r'.*', 'Good\nBetter')
print(ret.group())

ret = re.finditer(r'abc', 'abcABCAbC')
for r in ret:
    print(r.group())
    
