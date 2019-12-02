#04-025.py

s1 = {1, 2, 3, 7}
s2 = {1, 2, 3, 4, 5}
print(id(s1), s1, s2)
s1.update(s2)
print(id(s1), s1, s2)
s1.remove(1)
s1.remove(3)
print(s1)
s1.intersection_update(s2)
print(s1)
s1.add(9)
s1.add((3, 4, 6))
print(s1)




