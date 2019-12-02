#06-006.py

import re

msg = 'julie 010-123-1234 peter 011-1234-1234 office 031-123-1234'
r = re.finditer(r'01[0-26-9]-[0-9]{3,4}-[0-9]{4}', msg)
for m in r:
    print('Phone number :', m.group())
