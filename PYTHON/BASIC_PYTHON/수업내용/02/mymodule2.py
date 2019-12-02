#mymodule2.py

import mymodule1

print('mymodule2 - name : ' + __name__)
if __name__ == '__main__':
    print ('main module!')
else:
    print (__name__ + ' is a sub module!')   


