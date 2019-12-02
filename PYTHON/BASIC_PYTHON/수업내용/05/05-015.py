#05-015.py

class Horse:
    power = 80
    def run(self, speed):
        print("Run! ", self.__class__)
        self.speed = speed

class Ass:
    power = 100 
    def carry(self, weight, distance):
        print("Carry!! ", self.__class__)
        self.weight = weight
        self.distance = distance
        
class Mule (Ass, Horse):
    def printRun(self):
        print("power : ", self.power, ", speed : ", self.speed)
    def printCarry(self):
        print('power : {}, weight : {}, distance : {}'.format(self.power, self.weight, self.distance))

m = Mule()
m.run(50)
m.carry(100,20)

m.printRun()
m.printCarry()

##Mule().run(10)    # 가능

print(Mule.__mro__)
