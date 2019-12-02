
a = [1, 2, 3, 4,5, 6, 7, 8, 9, 10]

for x in a:
    print(x)

for x in range(5):
    print(x)

print('============================')


print(max(a[0], a[2]))
print(max(a))

print('============================')


## b = [1, 4, 9, 16, ...] 을 만들고 싶다!?
b = []
## 1번 방법 (비효율의 극치!)
for x in a:
    b.append(x**2)

print(b)

## 2번 방법
b = [0] * len(a)
for i in range(len(a)):
    b[i] = a[i]**2

print(b)

## 3번 방법
b = [x**2 for x in a]
print(b)

print('============================')


c = [2, 8, 4, 6 , 1 , 7 ,3 , 9, 5]
m = max(c)
print(m)
## max값의 위치?
print(c.index(m))

print('============================')


## c의 요소들 중 홀수가 아닌 요소들을 배열 d에 받아 다 프린트
d = [x for x in c if not x%2]
print(d)

print('============================')


e = [12, 28, 14, 36, 41, 27, 43, 29, 15]
f = [x//10*10 for x in e]
print(f)

print('============================')
