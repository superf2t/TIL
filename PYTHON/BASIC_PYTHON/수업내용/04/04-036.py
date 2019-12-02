#04-036.py

d = { 'apple' : 1500, 'orange' : 500, 'banana' : 100, 'kiwi' : 700 }
print('min = ', min(d.items()), 'max = ', max(d.items()))
min_item = min(zip(d.values(), d.keys()))
max_item = max(zip(d.values(), d.keys()))
print('min = ', min_item, 'max = ', max_item)

print( sorted(d.items(), key=lambda x:x[1]) )
print( sorted(zip(d.values(), d.keys())) )


