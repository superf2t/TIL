

## 3행 4열 2차원 배열 만드는 방법!!
if 0:
    a = [ [0] * 4 for x in range(3) ]
    print(a)

    print('========================================')

## 문제 A4: [TST]지능형 기차
if 0:
##    a = [0] * 4
    people = [0] * 5
    for i in range(4):
##        a[i] = list(map(int ,input().split()))
        a = list(map(int ,input().split()))
        people[i+1] = (a[1] - a[0]) + people[i]
##        print(a)
    print(max(people))


if 0:
    people = []
    for i in range(4):
        a = list(map(int ,input().split()))
        people.append(a[1] - a[0])
    for i in range(1, 4):
        people[i] += people[i-1]
    print(max(people))


    print('========================================')

## 문제 B0: [TST]가장 많은 알파벳은?
if 0:
    getInput = input()
    cnt = []
    for i in range(26): cnt.append(getInput.count(chr(ord('a')+i)))
##    print(cnt)    
    print(chr(cnt.index(max(cnt))+ord('a')))


if 0:
    getLower = [ i for i in input() if i > 'Z']
    print(min(i for i in getLower if getLower.count(i) >= max([getLower.count(i) for i in getLower])))
    

    print('========================================')

## 문제 A9: [LAB]행과 열의 큰 값 찾기
if 0:
    n = int(input())
    row = []
    col = [0] * n
    for i in range(n):
        a = list(map(int, input().split()))
        row.append(sum(a))
        for j in range(n):
##            print(j)
##            print(a[j])
            col[j] += a[j]

##    print(row)
##    print(col)
    print( row.index(max(row))+1, col.index(max(col))+1 )

       
    
##    for i in range(n):
##        for j in range(n):
##            arr[i][j] = int(input())
##    print(arr)
        

    print('========================================')

## 문제 A8: [LAB]숫자맞추기
if 0:
    x, y = input().split()
    a = b = 0
    
    for i in range(4):
        if x[i] == y[i] : a = a + 1
        for j in range(4):
             if x[i] == y[j] and i != j: b = b + 1         

    print(f'{a}A{b}B')


    print('========================================')

## 문제 A7: [Bash] 숫자 범위 맞추기
if 0:
    result = ( 0 <= int(input()) <= 100) and "OK" or "X"
    print(result)

print('========================================')


## 문제 A6: [MLAB] 점수로 학점구하기 - if~else 활용
if 0:
    chg = "FFFFFFDCBAA"
    score = int(input())
    result = (0 <= score <= 100) and chg[score//10] or 'Error'
    print(result)

    print('========================================')


## 아래의 두 코드는 같은 기능을 함!!
if 0:
    r, c = map(int, input().split())
    a = [ [0] * c for i in range(r) ]
    a[0][2] = 1
    print(a)

if 0:
    r, c = map(int, input().split())
    a = []

    for i in range(r):
        b = [0] * c
        a.append(b)

    a[0][2] = 1
    print(a)


    print('위에서 re...')
    print('========================================')

## r, c를 입력 받아, r행 c열 2차원 배열 안에 다 0으로 채우기!
if 0:
    r, c = map(int, input().split())

    a = [ [0]  * c ] * r
##    print(a)

    a[0][0] = 30
    print(a)


    print('========================================')


if 0:
    a = [1, 2, 3]
    b = [4, 5, 6]
    c = a + b   ## [ [1, 2, 3], [4, 5, 6] ]이 아니라 [1, 2, 3, 4, 5, 6]이 됨!!!
    print(c)
    print('------------------')
    

    a = [[1, 2]]
    b = [[3, 4, 5]]
    c = a + b   ## [1, 2, 3, 4, 5,]이 아니라 [ [1, 2], [3, 4, 5] ]이 됨!!
    print(c)
    print('------------------')

    a = [10, 20]
    a *= 5
    print(a)
    a[3] = 50
    print(a) ## 1, 3, 5, 7, 9, ... 자리에 있는 공간은 다 달라! 그래서 4번째 요소만 바뀜!!
    print('------------------')
    
    a = [ [1, 2, 3] ]
    b = a * 3
    print(b)
    b[0][0] = 50
    b[1] = 100
    print(b)            ## 하아아아아아아 헷갈령
    print('------------------')
    


    print('========================================')

if 0:
    a = [1, 2, 3, 4, 5, 6, 7, 8]
    print(a)

    b = ' '.join(map(str, a))
    print(b)

    c = str(a[1:-1]).replace(', ', '' )
    print(c)


    print('========================================')

## 문제 A5: [실무C 3-4] 비교 연산자의 사용, 2,3,5의 배수 판단하기

if 0:

    def compare(num):
        if not (num % 2) : return 2
        if not (num % 3): return 3
        if not (num % 5): return 5
        return 0
        
    print('3 =>', compare(3))
    print('62 =>', compare(62))
    print('25 =>', compare(25))
    print('157 =>', compare(157))


if 0:
    
    def compare(num):
        return 2 if not (num % 2) else 3 if not (num % 3) else 5 if not (num % 5) else 0
    
    print('3 =>', compare(3))
    print('62 =>', compare(62))
    print('25 =>', compare(25))
    print('157 =>', compare(157))


if 0:
    
    def compare(num):
        return not (num%2) and 2 or not (num%3) and 3 or not (num%5) and 5 or 0
    
    print('3 =>', compare(3))
    print('62 =>', compare(62))
    print('25 =>', compare(25))
    print('157 =>', compare(157))


    print('========================================')

if 0:
    import dis

    def func1(a):
        if a == 0:
            print("a == 0")

    def func2(a):
        if not a:
            print("a == 0")

    dis.dis(func1)
    dis.dis(func1)

    print('========================================')

if 0:
    a = 1
    b = 2
    c = 3
    d = 4
    e = 5
    if a<b<c<d<e:
        print(True)


    print('========================================')


if 0:
    ## Python 수행 흐름의 분기점!?!?!? - 이것으로 scope 구분됨!! (블럭 { } 이 없잖아!)

    a = 10
    if a < 20 :
        b = 1
    else :
        b = 2
    ## a는 전역변수이다 당연히. 그럼 b는??? => b 또한 전역변수이다!!!!

    for x in range(10):
        print(x)
    ## 그렇다면 x는? => x 또한 전역변수이다!!

    print(globals()) ## => 확인해보면 b와 x 모두 전역 namespace에 들어가있다는 것을 알 수 있음!!


    def func(a, b):
        ret = a + b
        print('나는 locals() : ')
        print(locals())
        return ret
    ## a, b, ret 모두 지역변수!

    func(1, 2)
    print('나는 globals() : ')
    print(globals())

    print('--------------------')

    globals()['yongnam'] = 'good'
    print(globals())
    del globals()['yongnam']
    print(globals())
    ## 추가적으로 추가, 삭제도 가능하넹!

    print('========================================')

if 0:
        
    print(chr(97))
    print(ord('a'))

    print('========================================')

if 0:
        
    ucmd = input()
    eval(ucmd)


    ## 1. dir()
    ## 2. 10
    ## 3. a = 10
    ## 4. 10+20
    ## 이 중에서 입력으로 불가능한 것은?
    ## ans : 3번!!
    ##         ㄴ  Why?: a = 10. 즉, 대입"문"이므로!!
    ##                          eval에는 expression(식)만 가능하고, statement(문)을 받을 수는 없다!
    ##                          ( dir()은 "식 (expression)"임!! )

    print('========================================')

if 0:
    import sys


    ## range와 list의 차이점!

    a = range(1, 99)
    print(a, sys.getsizeof(a))

    print(len(a))
    print(a[2])
    print(a[2:5])


    b = range(6, 66, 6)
    print(b, sys.getsizeof(b))
    ## a와 b는 다른데 크기가 똑같다!!! 오오




    aa = list(range(1, 99))
    print(aa, sys.getsizeof(aa))

    print(len(aa))
    print(aa[2])
    print(aa[2:5])  ## 여기에서 차이가 남!!


    bb = list(range(6, 66, 6))
    print(bb, sys.getsizeof(bb))
    ## a와 b는 list 컨테이너가 아닌 range이지만,
    ## 이렇게 list처럼 만들어 준다면 결과는 달라진다!!|\

    print('========================================')


if 0:
    ## 10번 반복!
    for i in range(10):
        print(i)
        if i == 4 : break


    for i in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]:
        print(i)
        if i == 4 : break
    ## 이 둘의 차이점은?? : 메모리!! (interning이 안 되었다면 ㅎ)
    ## 하지만 range의 경우에는 for문을 추가적으로 더 도는 것이기 때문에 좀 더 오래 걸린다고 함!


        

