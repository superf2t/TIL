#06-026.py

import re
msg = 'Good Morning!\nGood Afternoon!\nGood Evening!'
pattern = re.compile(r'^G(.*)ing!$', re.MULTILINE)
#pattern = re.compile(r'^G(.*)ing!$')
ret = pattern.finditer(msg)

print('Matched List')
for r in ret:
    print(r.group())
else :
    print('DONE')

