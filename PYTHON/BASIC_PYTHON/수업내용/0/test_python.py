## 문제 A0: [TST] 귤 판매
if 0:
    n = int(input())
    a = list(map(int, input().split()))
    a = [ x for x in a if x >=10 ]
    print(len(a))
    for i in a:
        print(i, end=' ')


## 문제 A2: [TST]단어 세기
if 0:
    while True:
        a = dict()
        inputStr = input().split()
        if inputStr[0] == 'END' : break
        for x in inputStr:
            a.setdefault(x, 0)
            a[x] += 1
        b = list(a.keys())
        b.sort()
        for x in b:
            print(x, ":", a[x])



## 문제 A4: [TST]문자열 변환
if 0:
    n = int(input())
    a = []
    for i in range(n):
        b = input().split()
        a.append(b)
    m = int(input())
    content = [ input() for x in range(m) ]
    result = str()
    for i in content:
        flag = False
        for j in range(len(a)):
            if i == a[j] [0]:
                result += a[j][1]; break
        else: result += i
    print(result)
        


## 문제 A1: [TEST] 초콜릿 공장
if 0:
    n = int(input())
    result = 0
    for i in range(n):
        flag = True
        pojangL = dict()
        pojangH = dict()
        a = input().split() # list
        for i in a[0]:
            pojangL.setdefault(i, 0)
            pojangL[i] += 1
            if pojangL[i] > 1 :
                result += 1
                flag = False
                break
            if flag == False: break
        if flag == False:
            continue
        for i in a[1]:
            pojangH.setdefault(i, 0)
            pojangH[i] += 1
            if pojangH[i] > 1 :
                result += 1
                flag = False
                break
            if flag == False: break
        if flag == False:
            continue
        cnt = 0
        for i in pojangL:
            pojangH.setdefault(i, 0)
            pojangH[i] += 1
            if pojangH[i] > 1: cnt += 1
            if cnt > 2:
                flag = False
                break
        if flag == False:
            result += 1
            continue

    print(result)





## 문제 A5: [TST]합의 회문수
if 0:
    def makeNum(n, le):
        num = int(0)
        for i in range(le):
            num *= 10
            num += int(n[-i-1])
        return num
    
    n = int(input())
    for i in range(n):
        val1 = list(input())
        val2 = [ val1[-x-1] for x in range(len(val1)) ]
        val1 = makeNum(val1, len(val1))
        val2 = makeNum(val2, len(val2))
        val3 = list(str(val1 + val2))
        le = len(val3)//2
        flag = True
        for i in range(le):
            if val3[i] != val3[-i-1] :
                flag = False
                break
        if flag == True: print("YES")
        else: print("NO")
##        print(val3)




## 문제 A6: [TST]UNIQUENESS
if 0:
    n = int(input())
    a = list(input().split())
    d = dict()
    for i in a:
        d.setdefault(i, 0)
        d[i] += 1
    flag = False
    for i in d:
        if d[i] >= 2:
            flag = True
            print(i, end=' ')
            for j in range(len(a)):
                if i == a[j]: print(j+1, end=' ')
            print()
    if flag == False: print('unique')




## 문제 A3: [LAB]문자열 찾기
if 0:   
    inputStr = input()
    koi = ioi = 0
    le = len(inputStr)
    for i in range(le):
        if i > le-2: break
        if inputStr[i] == 'K':
            if inputStr[i+1]=='O' and inputStr[i+2]=='I':
                koi += 1
        elif inputStr[i] == 'I':
            if inputStr[i+1]=='O' and inputStr[i+2]=='I':
                ioi += 1
    print(koi, ioi, sep='\n')





## 문제 A7: [TST]휴대폰번호 정렬
if 1:
    n = int(input())
    first = list(map(int, input().split()))
    nums = []
    result = []
    for i in range(n):
        nums.append(input())
    for i in first:
        a = []
        for j in nums:
            if j[2] == str(i):
                a.append(j)
        le = len(a)
        if le >= 2 :
            b = []
            for i in range(le):
                b.append(a[i].split('-'))
                print(b)
            for i in range(le-1):
                for j in range(le):
                    if len(b[i][1]) < len(b[j][1]) or (len(b[i][1]) == len(b[j][1]) and int(b[i][1]) > int(b[j][1]) ) :
                        a[i], a[j] = a[j], a[i]        
        elif le == 1: result.append(a[0])

    print('\n'.join(result))




    
