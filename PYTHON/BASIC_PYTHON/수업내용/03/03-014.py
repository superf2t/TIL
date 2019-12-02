#03-014.py

mydata = ( ('Apple', 'Red', 600),
                 ('Kiwi', 'Brown', 300),
                 ('Banana', 'Yellow', 200) )

# for문과 '{}...'.format() 사용
for x in mydata :
    
    ##print('{0} : price is {2}, color is {1}'.format(x[0], x[1], x[2]))
    
    ##print(x[0], ': price is ', x[2], ', color is ', x[1])

    ## unpack !!!!!!!!!!    
    print('{0} : price is {2}, color is {1}'.format(*x))

    ##print("%s : price is %d, color is %s" % (x[0], x[2], x[1]))

    ##print(x[::-1])


for a, b, c in mydata:
    print(f"{a} : price is {c}, color is {b}")
    
