#06-002.py

import re

def check(pw):
    if len(pw) < 8: return False
    bs = ( r'[0-9]+', r'[A-Z]+', r'[~!@#$%^&*]+')
    for x in bs:
        if re.search(x, pw) == None : return "NO"
    return "YES"


print(check(input()))

