
## compact
if 0:
    def compact(iterablethings):
        a = []
        idx = 0
        for x in iterablethings:
            if idx == 0 or x != a[idx -1] :
                a.append(x)
                idx += 1
        return iter(a)

##    print(compact(n**2 for n in [1, 2, 2]))
    print('=============================================')



## circle
if 0:
    import math
    
    class Circle:
        
        def __init__(self, radius=1):
            self.__radius = radius
            self.__diameter = 2 * radius
            self.__area = radius**2 * math.pi

        @property
        def radius(self):
            return self.__radius
           
        @radius.setter
        def radius(self, radius):
            if radius < 0 : raise ValueError("Radius cannot be negative")
            self.__radius = radius
            self.__diameter = 2 * radius
            self.__area = radius**2 * math.pi

        @property
        def diameter(self):
            return self.__diameter
           
        @diameter.setter
        def diameter(self, diameter):
            if diameter < 0 : raise ValueError("Radius cannot be negative")
            self.__diameter = diameter
            self.__radius = diameter/2
            self.__area = self.__radius**2 * math.pi

        @property
        def area(self):
            return self.__area

        @area.setter
        def area(self, diameter):
            raise AttributeError

        def __repr__(self):
            return f'Circle({self.__radius})'

        def printCircle(self):
            print(self.__radius, self.__diameter, self.__area)
    

    print('=============================================')


    
#05-035.py
if 0:
    def mygenerator(start, stop, step=1):
        curr = start
        while curr <stop:
            yield curr
            curr +=step
        return

    a = mygenerator(1, 20, 2)

    for i in a:
        print (i)
        if i == 5: break

    print(next(a))
    print(next(a))
    print(next(a))




    print('=============================================')




#05-033.py
if 0:
    class MyIterator:
        def __init__(self, start, stop, step=1):
            self.curr = start
            self.stop = stop
            self.step = step
        def __iter__(self):
            return self
        def __next__(self):
            if self.curr < self.stop:
                curr = self.curr
                self.curr += self.step
                return curr
            else:
                raise StopIteration()
        def __len__(self):
            return (self.stop - self.curr)
        def __str__(self):
            return str(list(self))
        
        def __getitem__(self, n):
            if type(n) == int:
                if n > len(self)-1: raise IndexError
                if n < 0:
                    if (-n) > len(self) : raise IndexError
                    return self.stop + (n)
                return self.curr+n
            else:
                newN = str(n).split(',');       newN[0] = newN[0].split('(')
                start = int(newN[0][1]);    end = int(newN[1])
                if start > len(self)-1 or end > len(self)-1: raise IndexError
                if start < 0:
                    if (-start) > len(self) : raise IndexError
                    start = len(self) + start
                if end < 0:
                    if (-end) > len(self) : raise IndexError
                    end = len(self) + end                 
                return [x for x in range(self.curr+start, self.curr+end, self.step)]
            
    a = MyIterator(1, 4)

    for i in a:
        print(i)
    print('------')
    
    a = MyIterator(1, 4)
    print( len(a) ) # 개야매
    print('------')
    
    a = MyIterator(3, 9)
    print(a[-1])
    print('------')
    
    a = MyIterator(3, 9)
    print(a[5:-3])
    print('------')
    
    a = MyIterator(1, 4)
    print(a)
    print('------')
    
    print(dir(a))

    print(range(5, 1))
    a = [1, 3, 5, 7, 9]
    print(a[2:-1])
    print(a[1:0])


    print('=============================================')



#05-012-namespace.py
# __init__  : need to call
if 0:

    class Mammal:
        mCnt = 0
        oCnt = 0
        def __new__(cls):   # 이 cls는 항상 Mammal일까? : super(). ~~ 를 통해 부모를 호출한 자식들 클래스일 수 있다!!
            cls.hidoyi = 19
            cls.age = 1
            print("Mammal new : ", cls.__name__)
            return super().__new__(cls) 
        def __init__(self): # 이 self도 마찬가지이다!! (Mammal의 객체이거나 자식클래스(Dog, Cat, Pig)의 객체일 수도)
            print("Mammal init ", self.__class__)
            Mammal.mCnt += 1
        @staticmethod
        def printCnt():
            print(Mammal.mCnt, ' Mammals.')

                
    class Dog(Mammal):
        def __new__(cls):
            print("Dog new ")
            return super().__new__(cls)
        def __init__(self):
            Mammal.__init__(self)
            Dog.oCnt += 1  # Dog.oCnt = Dog.oCnt + 1
            #print(id(Mammal.oCnt), id(Dog.oCnt))
        def printCnt(self):
            print(Dog.oCnt, ' Dogs.')


    class Cat(Mammal):
        def __new__(cls):
            print("Cat new ")
            return super().__new__(cls)   
        def __init__(self):
            Mammal.__init__(self)
            Cat.oCnt += 1
            #print(id(Mammal.oCnt), id(Cat.oCnt))
        def printCnt(self):
            print(Cat.oCnt, ' Cats.')

            
    class Pig(Mammal):
        def __new__(cls):
            print("Pig new ")
            return super().__new__(cls)
        def __init__(self):
            Mammal.__init__(self)
            #super().__init__()
            Pig.oCnt += 1
           # print(id(Mammal.oCnt), id(Pig.oCnt))
        def printCnt(self):
            print(Pig.oCnt, ' Pigs.')

            
    def printMOCnt (name, ns) :
        try :
            if ns['mCnt'] : print(name, 'mCnt', ns['mCnt'])
        except KeyError: pass

        if ns['oCnt'] : print(name,'oCnt', ns['oCnt'])

        

    ##m = Mammal()
    ##m.printCnt()

    a = [Dog(), Cat(), Pig()]
    Mammal.printCnt()
    a[0].printCnt()

    ##for x in [Mammal, Dog, Cat, Pig]:
    ##    print(x.__dict__)
    import pprint
    for x in [Mammal, Dog, Cat, Pig]:
        pprint.pprint(x.__dict__)

    
    print('=============================================')



## 05-008 classmethod
if 0:
    class AccountLoan:
    
        baseRate = 0.05
        
        def __init__(self, rate, amount):
            self.rate = rate
            self.amount = amount
            
        def getInterest(self):
            myrate = AccountLoan.baseRate + self.rate
            return int(self.amount * myrate)
        
        @classmethod
        def changeRate(cls, baseRate):
            if baseRate > 0.1:
                print("plz check again")
            else:
                cls.baseRate = baseRate



    print(AccountLoan.baseRate)

    a = AccountLoan(0.03, 10000)
    b = AccountLoan(0.02, 10000)

    print(a.amount, a.baseRate, a.rate, a.getInterest())
    print(b.amount, b.baseRate, b.rate, b.getInterest())

    AccountLoan.changeRate(0.04)
    ##AccountLoan.baseRate = 0.04
    ## 왜 바로 접근해도 되는데 굳이 함수를 만들어서 위처럼 접근하는가?
    ## Ans: 위의 함수를 보면, 여러가지 statement가 들어가 있는데,
    ##          바로 접근을 해버리면 이상한 값을 대입하면 바로 바뀌기는 하지만
    ##          잘못된 값을 줘버려도 그냥 적용. 하지만 그것을 방지할 수 있음!

    print(AccountLoan.baseRate)


    print(a.amount, a.baseRate, a.rate, a.getInterest())
    print(b.amount, b.baseRate, b.rate, b.getInterest())
    
    print('=============================================')


print('=====================================================')

#  dir()  : namespace에 접근하는 것이 아니라, 객체가 할 수 있는 일에 대해서 다 나열하는 것도 아니라!
#             객체의 주요 기능 등 객체에 대해서 대략적으로 알 수 있음

#  hash() : 가짜 주소 (실제 메모리 주소는 아님!)
