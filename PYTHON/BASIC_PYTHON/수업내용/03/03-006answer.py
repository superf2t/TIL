#03-006.py

# 2의 배수면 2, 3의 배수면 3, 5의 배수면 5를 2,3,5 배수가 아니면 0을 리턴한다
# 2의 배수면서 3의 배수이면 2의 배수로 출력, 3의 배수면서 5의 배수면 3을 출력한다

def compare(num):

    if not num % 2 : return 2
    if not num % 3 : return 3
    if not num % 5 : return 5
    return 0

print('3 =>', compare(3))
print('62 =>', compare(62))
print('25 =>', compare(25))
print('157 =>', compare(157))
