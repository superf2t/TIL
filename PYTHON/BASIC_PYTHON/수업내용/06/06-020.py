#06-020.py

import re

ret = re.findall(r'wow', 'wowowowow')
for t in ret:
    print("Matched : " + t)
