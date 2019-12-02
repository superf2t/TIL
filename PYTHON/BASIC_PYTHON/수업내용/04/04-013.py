#04-013.py

scores = [ 80, 80, 30, 80, 70, 70, 70, 90 ]
scores.sort()
first, *middle, last = scores
print(type(middle), middle)
avg = sum(middle)/len(middle)
print(avg)
