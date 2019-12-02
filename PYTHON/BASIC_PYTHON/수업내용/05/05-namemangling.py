class Parent1(object): 

  #_Parent1
    __var = 10 
 
    def __init__(self,*args): 
        print('Parent 1 init') 
 
    def method(self): 
        print('Parent 1 method') 
 
    __method = method
    
    def var(self): 
        print(self.__var) 

class Parent2(object):

    def __init__(self,*args): 
        print('Parent 2 init')
      
    def method(self):
        print('Parent 2 method')
        
    __method = method
  
class MySubClass(Parent1, Parent2): 

    def __init__(self, *args):
         print('Child init')
         Parent1.__init__(self)
         Parent2.__init__(self)
         
    def method1(self,*args): 
        print('Child method1--')
        #super().method1()
        self._Parent1__method()
        self._Parent2__method()
        
    def method_p1(self):
        self._Parent1__method() 

    def method_p2(self):
        self._Parent2__method()
        
m = MySubClass() 
m._Parent1__method()
m._Parent2__method()
m.method_p1() 
m.method_p2() 
m.var() 
Parent1()._Parent1__method() 



