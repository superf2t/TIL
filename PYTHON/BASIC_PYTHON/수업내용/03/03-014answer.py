#03-014answer.py

mydata = ( ('Apple', 'Red', 600),
                 ('Kiwi', 'Brown', 300),
                 ('Banana', 'Yellow', 200) )

# for문과 '{}...'.format() 사용

for row in mydata:
    name, color, price = row
    print('{} : price is {}, color is {}'.format(name, price, color))
    #print('{0} : price is {2}, color is {1}'.format(*row))
        
