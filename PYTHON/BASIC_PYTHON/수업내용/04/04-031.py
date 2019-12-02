#04-031.py

mydata = [ {'x':2, 'y':3}, {'x':4, 'y':1}, {'x':3, 'y':2}, {'x':1, 'y':4} ]
#mydata.sort()   # TypeError
mydata.sort(key=lambda x:x['x'])
print(mydata)

