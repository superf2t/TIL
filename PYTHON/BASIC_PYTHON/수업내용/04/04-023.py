#-*- coding: utf-8 -*-
#04-023.py

u1 = '핮핳'
b1 = u1.encode(encoding='utf-8')
b2 = u1.encode(encoding='cp949')
b3 = u1.encode(encoding='euc-kr')
print(len(u1), len(b1), len(b2), len(b3))
print(u1[0], u1[1])
print(b1[0], b1[1], b2[0], b2[1], b3[0], b3[1])
print(chr(65), chr(97), chr(b1[0]), chr(b1[1]))

u1 = b1.decode(encoding='utf-8')
u2 = b2.decode(encoding='cp949')   
u3 = b3.decode(encoding='euc-kr')
print(u1, u2, u3)
#u1 = b1.decode(encoding='cp949')
#u2 = b2.decode(encoding='euc-kr')
u3 = b3.decode(encoding='cp949')
print(u3)
