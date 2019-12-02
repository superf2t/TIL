#04-005.py

def printDetail(a):
    print(a)
    for x in a:
        print(type(x), x)

printDetail(([1, 2, 3], [4, 5]))
printDetail([(1, 2, 3), (4, 5)])

printDetail({1:100, 2:90})        
printDetail({'kim':100, 'park':90})
printDetail({'kim': [1, 20], 'park': [2, 30]})  
printDetail({('kim', 30):100, ('park', 35):90})
#printDetail({ ['kim', 30]:100, ['park', 35]:90 })
#printDetail({ {'kim', 30}:100, {'park', 35}:90 })
#printDetail({ [1, 2, 3], [4, 5] })
#printDetail({ {1, 2, 3}, {4, 5} })

