#05-029.py

a = 10
b = '10'
str = 'happy'
c, d, m = 0, 0, 'x'
try :
    c = a/0
    #d = b + 10
    #m = str[5]
except (ZeroDivisionError, OverflowError, FloatingPointError) as msg:
    print("Arithmetic Error!!", msg)
except TypeError as msg:
    print("TypeError !!", msg)
except Exception as msg:
    print("Exception !!", msg)
else:
    print(c, d, m)
finally:
    print('done')

