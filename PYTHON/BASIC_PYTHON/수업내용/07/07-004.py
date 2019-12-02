#07-004.py

myfile = open('C:\\MypythonFiles\\TextFiles\\letter2.txt', 'w')
myfile.write('Take care! See u later~\n')

myfile = open('C:\\MypythonFiles\\TextFiles\\letter2.txt', 'r')
msg = myfile.readlines()
print(msg)

