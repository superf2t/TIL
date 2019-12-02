#07-015.py
if 0:
    import os, glob

    class filedirlists:
        
        def __init__(self, cmd):
            self.dircnt = 0
            self.filecnt = 0
            self.cmd = cmd

        def printTree(self, cmd, depth):
            for x in glob.glob(cmd + '\\*'):
                prefix =  '|--' if depth == 0 else '|' + '--' * depth + '|--'
                if os.path.isdir(x):
                    self.dircnt += 1
                    print(prefix + os.path.basename(x))
                    self.printTree(cmd, depth + 1)
                elif os.path.isfile(x):
                    self.filecnt += 1
                    print(prefix + os.path.basename(x))
                else:
                    print(prefix + 'unknown : ', x)

    a = filedirlists('C:\\MyPython\\*')
    a.printTree('C:\\MyPython\\*', 0)
    print('total ', a.dircnt, 'directories', a.filecnt, 'files')
            
            
    print('===============================')

    if 0:
        def tree(path, depth):
            global dircnt, filecnt    
            for x in glob.glob(path + '\\*'):
                prefix =  '|--' if depth == 0 else '|' + '--' * depth + '|--'
                if os.path.isdir(x):
                    dircnt += 1
                    print(prefix + os.path.basename(x))
                    tree(x, depth + 1)
                elif os.path.isfile(x):
                    filecnt += 1
                    print(prefix + os.path.basename(x))
                else:
                    print(prefix + 'unknown : ', x)

        os.chdir('C:\\')
        tree('.', 0)       
        print('total ', dircnt, 'directories', filecnt, 'files')





#07-014.py
if 1:
    import os, glob

    a = glob.glob('*')
    print(type(a), a, sep='\n') # list는 이렇게 프린트하면 바로 리스트로 나옴!
    print(" ".join(x for x in a))

    
    a = glob.iglob('*')
    print(type(a), a, sep='\n')
    print(" ".join(x for x in a))  # generator은 이렇게 프린트 하자!!


#07-010.py
if 0:
    import shelve

    class A:
        def __init__(self, a, b):
            self.num1 = a
            self.num2 = b

        def printSum(self):
            print(self.num1 + self.num2)

    with shelve.open("myobj") as myShelf:
        a = A(20, 50)
        myShelf["myA"] = a
        myB = myShelf["myA"]
        myB.printSum()



## 파일 관련
if 0:
    import os

    print(os.getcwd())
    f = open('..\\TextFiles\\letter.txt', 'r')
    fa = open('..\\TextFiles\\a.txt', 'w')
    fb = open('..\\TextFiles\\b.txt', 'w')

    lines = f.readlines()
    sind = lines.index("Options: \n")
    eind = lines.index("\n")

    fa.write(''.join(lines[sind:eind]))

    newlines = [ '[{}] {}'.format(len(lines[i].strip()),lines[i]) for i in range(sind,eind) ]
    fb.write(''.join(newlines))

    f.close()
    fa.close()
    fb.close()



## 문제 B9: [TST] 긴 자릿수 나눗셈
if 0:
    while True:
        n = int(input())
        m = int(input())
        if n * m == 0 : break
        if n < m : n, m = m, n
        print(n//m)
        
##문제 C0: [TST]긴 자릿수 곱셈
if 0:
    while True:
        a = list(map(int, input().split()))
        if a[0] == 0 : break
        print(a[0]*a[1])



##
if 0:
    import re

    a = ' \ti  \n   am     a Grut!!        \t\t\t     '
    # => i am a Grut!!로!

    ret = ' '.join(a.split())
    print(ret)

    ret = re.sub(r'\s+', ' ', a).strip()
    print(ret)
    
    ret = ' '.join(re.sub('\s+', ' ', a).split())
    print( ret )
    





    
#06-016.py
if 0:
    import re

    def printMatch(pstr, data):
        print(pstr)
        print(data)
        pattern = re.compile(pstr)
        for x in data :
            mc = re.search(pattern, x)
            if mc :
                print('{}~{}에 {}존재'.format(mc.start(), mc.end(), mc.group()))
                print("따로 출력(연 / 월 / 일) : ", mc.group(1), "/", mc.group(2), "/", mc.group(3))
                print(f'year = {mc.group(1)}, month = {mc.group(2)}, day = {mc.group(3)}')
            else:
                print('NO Match')

    data = ('1990-09-12', '2020-12-31', '2099-10-32', '89-01-08', '1999-05-33')
    printMatch(r'\b((?:19|20)\d{2})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])\b',  data)         #XXXXXXX 에 패턴을 작성한다 





if 0:
    히도이 = 1
    대다내=2
    print(히도이, 대다내)
