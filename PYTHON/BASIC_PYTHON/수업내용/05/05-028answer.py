#05-028answer.py

class MyList:    
    def __init__(self, values=None):
        if values is None :
            self.values = []
            self.size = 0
        else :
            self.values = values
            self.size = len(values)        
    def __len__(self):
        return len(self.values)

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
        # 처음 item 반환, item이 없으면 None 반환
        return self.values[0] if self.size > 0 else None
    
    def last(self):
        # 마지막 item 반환, item이 없으면 None 반환
        return self.values[-1] if self.size > 0 else None
    
    def drop(self, n):
        # 처음 n개를 제외한 모든 item 반환, 부족시 None 반환
        return self.values[n:] if self.size > n else None
    
    def take(self, n):
        # 처음 n개의 item 반환, n개 부족시 전체 반환
        if self.size < n : n = self.size
        return self.values[:n]

    def __str__(self):
        # salf.values 의 내용을 [item1, item2, item3 ...] 형태의 문자열로 반환
        if self.size < 1: return "[]"        
        ret ="["
        for x in range(self.size-1):
            ret += (str(self.values[x]) + ", ")
        ret += str(self.values[-1])
        ret += "]"
        return ret
         
m = MyList([1, 2, 3, 4, 5, 6])
m.append(7)
del m[2]
print(m)
print(m.first(), m.last())
x = m.take(4)
y = m.drop(4)
print(x, y)

