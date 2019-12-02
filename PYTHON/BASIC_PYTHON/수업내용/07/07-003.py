#07-003.py

myfile = open('C:\\MypythonFiles\\TextFiles\\letter.txt')
mycont = myfile.read()
print(mycont)

myfile = open('C:\\MypythonFiles\\TextFiles\\letter.txt')
mycont = myfile.readlines()
print(mycont)
