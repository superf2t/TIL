#07-006.py

import os

try:
    with open('NONE') as fp:
        msg = fp.read()
        print(msg)
except IOError:
    print("File doesn't exist")

if os.access('NONE', os.F_OK) and os.access('NONE', os.R_OK) :
    with open('NONE') as fp:
        msg = fp.read()
        print(msg)
else:
    print("File doesn't exist or No read permission")


