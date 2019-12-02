#06-029.py

import re

def idcheck(id):
    ret =re.fullmatch(r'\d{6}-\d{7}', id)
    if ret == None: return id+"is Not an id"
    return re.sub(r'\d{7}', '*******', id)

print(idcheck('881103-1231233'))
print(idcheck('Julie Yoon'))
print(idcheck('1990-12-28'))
