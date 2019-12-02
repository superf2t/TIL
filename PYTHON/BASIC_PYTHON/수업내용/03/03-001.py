#03-001.py

a = 'Hello'

b = ( 1, 2,  # possible 
      3, 4 )


# \를 해주지 않으면 syntax error가 뜸!
if a == 'Hello' \
and 3 in b \
and len(b) == 4 :
    print ('Success!!')


def func(a, b, c, d):
    pass

func(10,    #이렇게 주석을 준다면? => 가능!
     20,
     30,
     40)

