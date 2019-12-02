#04-011.py

fruit = ['apple', 'mango', 'kiwi', 'orange']
test = ['a', 'z', 'A', 'Z', 'c'] 
fruit.sort()
print(fruit)
fruit.sort(reverse=True)
print(fruit)
r1 = sorted(test)
print(id(test), id(r1))
print('r1 = {}, test = {}'.format(r1, test))
test.sort(key=str.lower)
print('test = {}'.format(test))

