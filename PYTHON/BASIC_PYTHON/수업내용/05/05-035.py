#05-035.py

def mygenerator(start, stop):
    curr = start
    while curr <stop:
        yield curr
        curr +=1
    return

a = mygenerator(1, 10)

for i in a:
    print (i)
    if i == 5: break

##print(next(a))
##print(next(a))
##print(next(a))

b = range(1, 1 << 555)
print(b)
