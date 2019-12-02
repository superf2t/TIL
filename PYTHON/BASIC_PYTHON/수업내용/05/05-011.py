#05-011.py

class Horse:
    __horseCnt = 0
    def __init__(self, father, mother, name):
        self.__father = father
        self.__mother = mother
        self.name = name
        Horse.__horseCnt += 1
        
    def printInformation(self):
        print('Horse cnt : ', Horse.__horseCnt)
        print(self.__father, self.__mother, self.name)
        
    def __del__(self):
        Horse.__horseCnt -= 1        

    @property
    def father(self):
        return self.__father
    
    @father.setter
    def father(self, father):
        self.__father = father.lower()

    @property
    def mother(self):
        return self.__mother
    
    @mother.setter
    def mother(self, mother):
        self.__mother = mother.upper()
        #self.__mother = mother  

#본 예에서는 사용에 의미가 없음   h.horseCnt = 1, print(h.horseCnt)등으로 접근
    @property
    def horseCnt(self):
        return Horse.__horseCnt
    
    @horseCnt.setter
    def horseCnt(self, cnt):
        Horse.__horseCnt = cnt
        
h = Horse('A', 'B', 'Wind')
h.father = 'West'
h.mother = 'East'
h.name = 'Faster'
print(h.father, h.mother, h.name)
h.printInformation()




        
