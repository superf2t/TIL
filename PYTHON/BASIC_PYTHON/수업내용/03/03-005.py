#03-005.py

ch = 'c'
if 'f' <= ch <= 'z' :
    msg = 'YES'
else :
    msg = 'NO'
print(msg)

msg = 'YES' if 'f' <= ch <= 'z' else 'NO'
print(msg)

msg = 'f' <= ch <= 'z' and 'YES' or 'NO'
print(msg)


