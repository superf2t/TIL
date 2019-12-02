#04-030.py

fruits = [ ('apple', 'red', 1500), ('kiwi', 'brown', 300), ('banana', 'yellow', 300) ]
#fruits.sort()
fruits.sort(key=lambda x:x[0])  # same with fruits.sort()
print(fruits)

fruits = [ ('apple', 'red', 500), ('kiwi', 'brown', 300), ('banana', 'yellow', 300) ]
fruits.sort(key=lambda x: (x[2], x[1]) )  # same with fruits.sort()
print(fruits)

'''
fruits = [ ['apple', 'red', 1500], ['kiwi', 'brown', 300], ['banana', 'yellow', 600] ]
#fruits.sort()
fruits.sort(key=lambda x:x[0])  # same with fruits.sort()
print(fruits)
'''
