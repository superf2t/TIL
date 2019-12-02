#05-033.py

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
                if -n > len(self) : raise IndexError
                return self.stop + (n)
            return self.curr+n
        else:
            newN = str(n).split(',')
            newN[0] = newN[0].split('(')
            return [x for x in range(self.curr+int(newN[0][1]), self.curr+int(newN[1]), self.step)]
        
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
print(a[1:3])
print('------')
a = MyIterator(1, 4)
print(a)
print('------')
print(dir(a))


a = [1, 3, 5, 7, 9]
print(a[2:-1])
