#04-040.py

import datetime

a = range(1000)
start = datetime.datetime.now()
print( " ".join(  str(i for i in a) ) )
end = datetime.datetime.now()
t1 = (end-start)

start = datetime.datetime.now()
for i in a : print(i, end=' ')
end = datetime.datetime.now()
t2 = (end-start)

print('t1 =', t1)
print('t2 =', t2)


