#06-021.py

import re
pattern = re.compile(r'[0-9]{2}')
ret = pattern.finditer('123abc456')
print('Matched List')
for m in ret:
    print(m)
    #print(m.group())
else:  
    print('DONE')
        
