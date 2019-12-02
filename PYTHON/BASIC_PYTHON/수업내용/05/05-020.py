#05-020.py

class myMetaclass(type):
        def __new__(cls, clsname, bases, dct):
            assert type(dct['a']) is int, '"a" must be an integer'
            return type.__new__(cls, clsname, bases, dct)

class Simple(metaclass=myMetaclass):
##    a = 'happy'
    a = 123
    
s = Simple()
print(Simple.a)
