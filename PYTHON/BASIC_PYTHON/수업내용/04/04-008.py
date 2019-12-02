#04-008.py

import copy

fruit = ['apple', 'kiwi', 'mango', 'orange']
myfruit = copy.copy(fruit)
del myfruit[1]
myfruit.append('banana')
print(id(fruit), fruit)
print(id(myfruit), myfruit)



