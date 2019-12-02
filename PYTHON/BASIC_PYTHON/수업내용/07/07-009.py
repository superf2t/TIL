#07-009.py

import shelve
myShelf = shelve.open('myshelf')
fruits = ['orange', 'banana', 'apple']
myStr = 'hello!'
myValue = 100.2
myShelf['fruits'] = fruits
myShelf['myStr'] = myStr
myShelf['myValue'] = myValue
myShelf['myStr'] = 200.54
print(list(myShelf.keys()))
print(list(myShelf.values()))
print(myShelf['fruits'])
print(myShelf['myStr'])
print(myShelf['myValue'])
myShelf.close()
