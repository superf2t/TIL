#05-003.py

class Mammal:
    def __init__(self, name):
        self.name = name
        print("init 실행!!")
    def __del__(self):
        print(self.name, "deleted!")

def testfunc() :
    m = Mammal('Happy')
##   del m

testfunc()

