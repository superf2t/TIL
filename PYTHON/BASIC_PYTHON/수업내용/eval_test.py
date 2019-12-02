
vpre = input()
for i in range(10):
    exec( f'{vpre}_{i}={i*10}')
    #exec( vpre + '_' + str(i) + '=' + str(i*10))
print(globals())
