
## 문제 B8: [TST]문자까지의 문자열
if 1:
    a = 'abcdefghijklmnopqrstuvwxyz'
    a += a.upper()
    b = input()
    alphabet = ( b not in a and 'Error' or b)
    if alphabet == 'Error': print('Error')
    elif alphabet <= 'Z':
        for i in range(ord(alphabet), ord('Z')+1):
            print(chr(i), end='')
    else:
        for i in range(ord('a'), ord(alphabet)+1):
            print(chr(i), end='')





## 문제 B7: [Bash] 문자열 조작
if 0:
    linux = input().split()
    print(linux)
    print('{0} - owner: {1} group: {2} size: {3}'.format(linux[-1], linux[2], linux[3], linux[4]), end=' ')





## 문제 B6: [Bash] zero padding
if 0:
    n = int(input())
    for i in range(1, n+1):
        print('data{0}.log'.format(str(i).rjust(3, '0')), end=' ')





## 문제 B5: [Bash] 이름 만들기
if 0:
    n = int(input())
    for i in range(1, n+1):
        print('data{0}.log'.format(i), end=' ')




## 문제 B4: [Bash] 파일 이름 목록 작성
if 0:
    tmp = input()
    for i in range(1, 100, 2):
        print('{0}_{1}.png'.format(tmp, i), end=' ')




## 문제 B3: [Bash] 시간정보로 파일이름 만들기
if 0:
    time = input().split()
    time[0] = time[0].split('-')
    time[1] = time[1].split(':')
    print(time)
    print( '/home/user/myfile_{0}{1}{2}{3}{4}{5}.bak'.format( time[0][0][2:], time[0][1], time[0][2], time[1][0], time[1][1], time[1][2] ) )
    



## 문제 B2: [Bash] 디렉터리, 이름 분리
if 0:
    path = input().rsplit('/', 1)
    print('dir={0} name={1}'.format(path[0], path[-1]))




## 문제 B1: [Bash] 필드 분할 및 정렬
if 0:
    n = int(input())
    path = [ input().split(':')[0] for i in range(n) ]
    for i in sorted(path):
        print(i)
##    print(sorted(path), sep='\n')



print('이 아래부터는 2019-11-27 수업 시간 내용!')
print('========================================')




#04-039.py
if 0:
    import sys
    
    a = [x*2 for x in range(1, 600)]  #iterable
    g = (x*2 for x in range(1, 600))  #iterator
    # generator은 iterator이지만, iterator은 generator가 아니다! 즉, 포함관계 gen <= iter
    
    print(sys.getsizeof(a), a)
    print(sys.getsizeof(g), g)
    # generator은 size(메모리 크기)가 바뀌지 않고 고정되어 있음.
    # iterable 같은 경우, 크기가 작을 경우에는 메모리 작지만, 커지면 메모리도 비례해서 커짐!

    for i in range(5) : print(a[i], end=' ')    # iterable은 subscription 가능!!
##    for i in range(5) : print(g[i], end=' ')    # iterator은 subscription 불가능!!
    # subscription은 임의의 위치로 지정해서 가는 건데, iterator은 next로!
    # 결과적으로     for i in range(5) : print(g[i], end=' ')    는 불가능!!
    print()

##    print (next(a))   # list는 iterator이 아니기 때문에 next가 불가!!!!
    print (next(g))
    c = iter(a)
    print (next(c))

    r = range(10)
    for i in range(5) : print(r[i], end=' ')
##    print(next(r))    # range는 iterator가 아니다!!!!

    print('========================================')


#p.208
if 0:
    x = []
    for i in range(3):
        a = list(map(int, input().split()))
        x.append(a)

    print(x)

if 0:
    x = [ list(map(int, input().split())) for _ in range(3) ]
    print(x)


# p.207 map!!!
if 0:
    odd = [ 1, 3, 5, 7, 9, 11, 13 ]
    m = map(lambda x : x * x, odd)  # map은 iterator!!!
    next(m)
    next(m)         # iterator의 특징!!!!
    print(list(m))                # list(  ) 안에 넣어줌으로써 iterable로 만들어줌!
    print(list(m))                # next하면 다시 돌아갈 수 없음. 이미 다 끝났기 때문에 더이상 읽어올 수 없었던 것!

    student = 'Julie | 010-123-456 | 42 | F'
    print(student.split('|'))
##    m = map(str.strip, student.split('|'))
    m = map(lambda x : x.strip(), student.split('|'))
    print(list(m))

    print('========================================')




#04-029.py
if 0:
    nums='1237894673683038478236749192738623234234'

    if 1:
        cnt = {}
        for num in nums:
            cnt.setdefault(num, 0)
            cnt[num] += 1
        
    else:
        # 위에서 for문을 돌려서 만든 cnt를 Counter 메소드를 통해 한 번에 만들 수도 있음!
        from collections import Counter
        cnt = Counter(nums)

        
    print(cnt)



    # 1. 등장 횟수(빈도 수)를 기준으로 오름차순으로 정렬 가능!?!?
    # 어렵고도 신기함..!
    if 0:
        # 1-1)
        cnt_tmp = { i:cnt[i] for i in sorted(cnt, key = lambda x : cnt[x]) }
        print(cnt_tmp)
        
    else:
        
        # 1-2)
        cnt_tmp = { i:j for i, j in sorted(cnt.items(), key = lambda x : x[1]) }
        print(cnt_tmp)


    # 2. key 0 ~ 9까지의 ...
    ##cnt_tmp = dict.fromkeys("0123456789", 0)
    cnt_tmp = { k : cnt.get(k, 0) for k in "0123456789"}

    ##for i in cnt_tmp:
    ##    cnt_tmp[i] = cnt.get(i, 0)
    print(cnt_tmp)

    print('========================================')



## dictionary
if 0:
    exmpl = [ ('a', 3, 100), ('x', 1, 100), ('c', 2, 500) ]
    print(sorted(exmpl))    # exmple[?][0]을 기준으로 정렬이 됨!!
    exmpl.sort(key = lambda x : (x[2], x[1]))
                                # x는 exmpl의 item을 받게 됨!!!
                                # 그것을 통한 리턴이 튜플... 근데 x[2]를 기준으로 먼저 하고, 그 다음 x[1]
    print(exmpl)

    
    print('========================================')



## p.200
if 0:
    class A:

        # A.m1()으로 호출을 하든(원래 이렇게 사용!), a.m1()으로 호출을 하든 상관이 없이
        # => 클래스 정보를 주는 메소드
        @classmethod
        def m1(cls):    # class의 namespace를 사용
            pass             # && classmethod를 이용해서 생성자 만들 수 있음!

        def m2(self):   # 객체의 namespace를 사용
            pass

        @staticmethod
        def m3():
            pass

    
    print('========================================')


## p.197 dictionary
if 0:
    def func(**kwarg):
##        print(kwarg)
        return kwarg
    
    d = dict(hi=10, do=20, yi=30)
    print(d)
    dd = func(hi=10, do=20, yi=30)
    print(dd)
    
    print('{hi} {do} {yi}'.format(**d))    # value만! => == .format(hi=10, do=20, yi=30)
    print('{0} {1} {2}'.format(*d))         # key만! => == .format('hi', 'do', 'yi')
    print(*d)                                               # key만!


    print('========================================')



## p.172 04-015
if 0:
# s.split() : 구분자를 맨 뒤에 넣은 String을 split하면 1개의 빈 문자열아 추가된다!
# print('A:B:C:'.split(':')) => ['A', 'B', 'C', '']

    print('A:B:C:'.split(':'))
    
    def printL(a):
        print(len(a), a)
        
    printL('AB C\n\nAB\r\rAB\r\n'.splitlines())
    printL('AB C\n\nAB\r\rAB\r\n'.splitlines(keepends=True))
    printL('AB C\n\nAB\r\rAB\r\n'.split('\n'))
    printL('A\n'.split('\n'))
    printL('A\n'.splitlines())
    print(len('ABC'), 'ABC'.splitlines('\n'))
    print(len('ABC\n'), 'ABC\n'.splitlines('\n'))
    print(''.split('\n'), ''.splitlines())

    print('========================================')


## p.167 String
if 0:
    a = 'hidoyi'
    b = a + 'hoihoi'
    print(id(a), id(b))
    ## 둘은 서로 다른 주소 참조!!
    ## +연산자는 계속 새로운 객체를 만들어가는 연산자!


    print('========================================')



## p.156 tuple과 list
if 0:
    a = [2, 4, 5, 6, 1, 9, 8, 7, 5, 3]
    b = (2, 4, 5, 6, 1, 9, 8, 7, 5, 3)

    
##    a.sort()
##    print(a)
    r = sorted(a)
    print(r)
    print(a)    # sorted는 본체를 바꾸지 않음!! 리턴값을 활용!
    ## 하지만 sorted(a, inplace=True)로 사용하게 되면 본체도 바뀜!!


##    b.sort()  # tuple은 immutable하므로 sort할 수 없음!! (수정/갱신 못하잖아!)
    print(b)
    b = sorted(b)   # 본체에 다시 대입하는 것도 가능!!! list로 변함!!
    #(sorted는 어떤 iterator/able이든 list로 바꿔서 리턴한다는 의미!)
    print(b)

    print('========================================')
    

## p,150 04-005
if 0:
    def printDetail(a):
        print(a)
        for x in a:
            print(type(x), x)

    printDetail(([1, 2, 3], [4, 5]))
    printDetail([(1, 2, 3), (4, 5)])

    printDetail({1:100, 2:90})        
    printDetail({'kim':100, 'park':90})
    printDetail({'kim': [1, 20], 'park': [2, 30]})  
    printDetail({('kim', 30):100, ('park', 35):90})



    ## dictionary는 key값으로 list나 set을 받을 수 없음!!
    ##      - hashable이 아니기 때문!!
    
    #printDetail({ ['kim', 30]:100, ['park', 35]:90 })
    #printDetail({ {'kim', 30}:100, {'park', 35}:90 })



    ## set은 item으로 list나 set을 받을 수 없음!!
    ##      - hashable이 아니기 때문!!

    #printDetail({ [1, 2, 3], [4, 5] })
    #printDetail({ {1, 2, 3}, {4, 5} })

    print('========================================')



## p,148 04-004
if 0:
    
    ## set
    a = {1, True, 1.0}
    b = {True, 1.0, 1}
    c = {1.0, True, 1}
    print(a, b, c)
    ## set {  } : 중복된 값을 안 넣음!
    

    ## dictionary
    d = {1: 'abc', True : 'def', 1.0 : 'hidoyi'}
    print(d)
    ## 같은 key 값이 들어오면 갱신!! (없던 key 값이 들어오면 새로 만듦)


    print('========================================')



## p.149 실습1
if 0:
    import dis
    
    fruit = ('apple', 'kiwi', 'apple', 'apple', 'banana', 'orange', 'strawberry', 'apple', 'grape')

    ## 1
    def getIndexList(t, k):
        return [i for i in range(len(k)) if k[i] == t]
        
    ## 2
    def getIndexList2(t, k):
        r = []
        for i in range(len(k)):
            k[i] == t and r.append(i)
        return r

    dis.dis(getIndexList)
    dis.dis(getIndexList2)

    print(getIndexList('apple', fruit))
    print(getIndexList2('apple', fruit))


    print('========================================')


## 3행 4열 2차원 배열 만드는 방법!!
if 0:
    a = [ [0] * 4 for x in range(3) ]
    print(a)

    print('========================================')
