#04-024.py

s1 = {1, 2, 3, 7}
s2 = {1, 2, 3, 4, 5}
t = [3, 4, 5, 6, 8]
sb = {2, 3}
print(s1 | s2 | set(t))
print(s1.union(s2, t))
print(s1 & s2 & set(t))
print(s1.intersection(s2, t))
print(s1 - s2 - set(t))
print(s1.difference(s2, t))
print(s1 ^ s2)
print(sb.issubset(s1))
print(s1.issuperset(sb))

