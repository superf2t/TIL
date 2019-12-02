a = [1, 2, 3, 4]
print(sum(a))

def func(a):
##    del sum
    print(sum(a))

func(a)
print('global에서도, local에서도 sum메소드를 다 사용할 수 있다!')
print('=======================================')

sum = 100
del sum
print(sum(a))
##print('\'int\' object is not callable')
