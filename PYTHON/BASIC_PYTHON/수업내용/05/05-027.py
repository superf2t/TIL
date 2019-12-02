#05-027.py

class MyList:
    
    def __init__(self, values=None):
        if values is None :
            self.values = []
            self.size = 0
        else :
            self.values = [x for x in values]
            self.size = len(values)
        
    def __len__(self):
        return len(self.size)

# Exception 처리 필요
    def __getitem__(self, key):
        return self.values[key]

    def __setitem__(self, key, value):
        self.values[key] = value

    def __delitem__(self, key):
        del self.values[key]
        self.size -= 1
# --------------------------

    def __iter__(self):
        return iter(self.values)

    def __reversed__(self):
        return reversed(self.values)

    def append(self, value):
        self.values.append(value)
        self.size += 1
        
    def first(self):
        assert self.size > 0, "Nothing!"
##        if self.size == 0: return None
        return self.values[0]
        # 처음 요소 반환
    
    def last(self):
        assert self.size > 0, "Nothing!"
##        if self.size == 0 : return None
        return self.values[-1]
        # 마지막 요소 반환
    
    def drop(self, n):
        assert self.size > n, "Nothing!"
##        if self.size < n : return None
        return self.values[n:]
        # 처음 n개를 제외한 모든 요소 반환
    
    def take(self, n):
        assert self.size > n, "There are {} values".format(self.size)
##        if self.size < n : return None
        return self.values[0:n]
        # 처음 n개의 요소 반환

    def __str__(self):
##        if self.size < 1: return "[]"        
##        ret ="["
##        for x in range(self.size-1):
##            ret += (str(self.values[x]) + ", ")
##        ret += str(self.values[-1])
##        ret += "]"
##        return ret
        return str(self.values)

##m = MyList()
m = MyList([1, 2, 3, 4, 5, 6])
m.append(7)
del m[0:3]
##m.take(6)
print(m.values)


