#05-018.py

if 0:
    x = type(3)
    print(x(5) + 3)
    t = type('SeokMinZzang', (), {'name' : 'minZzang', 'hidoyi' : lambda x : x**3})
    print(t)
    ##print(t.name, t.hidoyi(10))

if False:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    t = type('A', (), {'a':10, '__init__': __init__})
    print("t's class : ", t)
    print(t.a)  #, t.x)
    ti = t(10, 20)  # instance 생성! (ti는 인스턴스, t는 클래스!)
    print(t.a, ti.x, ti.y)
    print(isinstance(ti, t), isinstance(ti, object))        # 인스턴스이니? (그 클래스로부터 인스턴스로 만들어졌니?)
    print(issubclass(t, type), issubclass(t, object))   # 상속 받았니? 자식이니?
    print(ti.__class__)

if 1:
    class A:
        def __new__(cls, arg):
            cls.inClassNamespace = arg
            return super().__new__(cls)
        def __init__(self, name):
            self.inInstanceNamespace = 3
            self.name = name
        def __call__(self, data):
            print(self.name, data)

    a = A("Kim")
    print('---------------')
    print(a.__dict__)
    print('---------------')
    print(A.__dict__)
    print('---------------')
    print(a.name)
    a(10)
