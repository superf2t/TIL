#02-020.py
import pprint as pp

msg = 'happy'

def func(a, b) :
    c = a + b
    pp.pprint(locals())
    return c

pp.pprint(globals())
print(func(10, 20))
