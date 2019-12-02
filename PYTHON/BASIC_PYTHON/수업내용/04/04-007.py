#04-007.py

fruit = ['apple', 'kiwi', 'mango', 'orange']
myfruit = fruit
myfruit[1] = 'banana'
del myfruit[2]
print (id(fruit), fruit)
print (id(myfruit), myfruit)

