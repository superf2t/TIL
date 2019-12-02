#04-009.py

Afruit = ['apple', 'kiwi', 'mango']
Bfruit = ['banana', 'orange']
fruit = Afruit + Bfruit
print (id(Afruit), id(Bfruit), id(fruit))
print (fruit)

one = [0] * 3 * 2
twoA = [[0] * 3] * 2
twoA[0][1] = 100
twoB = [ [0] * 3, [0] * 3 ]
twoB[0][1] = 100
print (one, twoA, twoB, sep='\n')
print (id(twoA[0]), id(twoA[1]) )
print (id(twoB[0]), id(twoB[1]) )
