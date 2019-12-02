#03-012.py

for i in range(10):
    if  not (i % 3) or  not (i % 2) : continue
    for j in range(10):
        if i == j : break
        print(i, j)

def func() :
    for i in range(10):
        for j in range(10):
            if (i+2) == j : return
            print(i, j)
print('---------------')
func()            
        

        
