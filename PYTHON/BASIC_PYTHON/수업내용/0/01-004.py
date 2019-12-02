
data = int(input('num? : '))
result = data//10*10
print(data, result)

a = [23, 45, 19, 29, 52, 47, 25, 66]
func = lambda x : x//10*10
print(type(func))
b = list(map(func, a))
print(b)
