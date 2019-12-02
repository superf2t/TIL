#02-014.py

##import module1 as m1, module1

##print(dir())

##a = 40
##b = 10
##print('%d + %d = %d' %(a, b, module1.add(a, b)))
##print('%d - %d = %d' %(a, b, module1.sub(a, b)))


# comment (Alt + 3)  uncomment (ALt + 4)

##from module1 import add
##
##print(dir())
##
##a = 40
##b = 10
##print('%d + %d = %d' %(a, b, add(a, b)))
##print('%d - %d = %d' %(a, b, sub(a, b)))  # NameError


from module1 import *
a = 40
b = 10
print('%d + %d = %d' %(a, b, add(a, b)))
print('%d - %d = %d' %(a, b, sub(a, b)))

##module1에서 _add로 이름 고치고, 실행하면 에러가 뜸!! not defined라고!!
##print('%d + %d = %d' %(a, b, _add(a, b)))

