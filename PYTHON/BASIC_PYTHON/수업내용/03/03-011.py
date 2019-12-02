#03-011.py

data = ( (1, 2, 3), (4, 5, 6), (7, 8, 9) )

print(data.index((4, 5, 6), 1))

for row in data :
    for c in row :
        print(c, end=' ')
    print()

for row in data :
    a, b, c = row 
    print(a, b, c)

for idx in range(0,3) :
    a, b, c = data[idx]
    print(a, b, c)


