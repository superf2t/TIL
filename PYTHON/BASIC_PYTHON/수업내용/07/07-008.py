#07-008.py

import shelve

myShelf = shelve.open('myshelf')
fruits = ['orange', 'banana', 'apple']
myShelf['fruits'] = fruits
print(myShelf['fruits'])
myShelf.close()
