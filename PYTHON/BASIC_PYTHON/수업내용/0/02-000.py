a = [23, 45, 19, 29, 52, 47, 25]

def func(*a):
    print(len(a), type(a), a)
    return None

func(10, 20, 30, 40)

func(a)

## unpack!!!
func(*a)



d = dict(zip(list('ABCDE'), range(1, 6)))
print(d)
## dictionary  d  unpack!!!
print('{E} {C}'.format(**d))
## a  unpack!!!
print('{3} {0} {6}'.format(*a))

## 앞의 두 개만 unpack!!!
one, two, *_ = a
print(one, two, _)

smallest, *_, biggest = sorted(a)
print(smallest, _ , biggest)



def func2(**a):
    print(len(a), type(a), a)

func2(x = 10, y = 20, z = 30)

