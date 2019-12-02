#05-010.py

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
        
h = Horse('A', 'B', 'Wind')
h.__father = 'West'
h.__mother = 'East'
h.name = 'Faster'
print(h.__father, h.__mother, h.name)
h.printInformation()
print(h.__dict__)


h._Horse__father = 'West'
h._Horse__mother = 'East'
print(h._Horse__father, h._Horse__mother, h.name)
h.printInformation()
print(h.__dict__)


###print(Horse.__horseCnt, h.__father, h.__mother)
##print(Horse._Horse__horseCnt, h._Horse__father, h._Horse__mother)
##h.printInformation()
        
