


print('============================')

cnt = int(input())
first = [ input().split(':')[0] for x in range(cnt) ]
print('\n'.join(first))
##for x in first:
##    print(x.split(':')[0])


print('============================')


name = input()

print('\n'.join(name))
##for x in name:
##    print(x)

print('============================')


a = [ int(input()) for i in range(9)]

m = max(a)
print(m)
print(a.index(m))

##a = []
##m = 0
##m_idx = 0
##def inputData():
##    for x in range(9):
##        a.append( int(input()) )
##
##def findMax():
##    global m, m_idx
##    m = max(a)
##    m_idx = a.index(m)
##
##def printResult():
##    print("%d %d" %(m, m_idx+1))
##
##inputData()
##findMax()
##printResult()

print('============================')


x = input().split()
print(x)
## a, b를 입력받아 그것의 합을 출력
a, b=map(int, input().split())
print(a + b)

print('============================')

