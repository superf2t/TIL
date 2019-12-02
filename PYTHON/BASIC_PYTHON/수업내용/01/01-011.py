#01-011.py
import operator

a, b = -1, 2
print(a**b, pow(a, b), (-1)**b, -1**b)

c = 123
print(c//100, c//10%10, c%10)

d, e = 10, 3
print(d//e, d%e, divmod(d, e), d/e)

mok, namo = divmod(d, e)
print(mok, namo)

arr = divmod(d, e)
print(arr[0], arr[1])






