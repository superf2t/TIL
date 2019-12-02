#02-021_nonlocal.py
v=1
def func():
    #v=2
    def subfunc1():
        #v=3
        def subfunc2():
            nonlocal v
            print(v)
        subfunc2()
    subfunc1()

func()
