#02-021_global.py

a = 100
def changeA(a):
    a = 10  # 지역변수 a를 사용
    print(a)
    
print(a)
changeA(a)
print(a)
print()

a = 200
def changeB():
    global a # 전역변수 a를 사용
    a = 10
    print(a)
    
print(a)
changeB()
print(a)
print()

a = 300
def changeC(a):
    global a  # 오류, 지역변수로 존재하는 a와 이름이 동일하면 안됨
    a = 10
    print(a)
    
print(a)
changeC(10)
print()

a = 400
def changeD(a):
    global b  # 전역변수 b가 생성
    b = 10
    print(a)
    
print(a)
changeD(10)
print(a)
print(b)  # 사용가
