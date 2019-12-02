#mymodule1.py
import mymodule2

print('mymodule1 - name : '+ __name__)
if __name__ == '__main__' :
    print ('main module!')
else:
    print (__name__ + ' is a sub module!')       



