#02-023.py

value = 3
def add_num(value, num=1):
    print(value)
    value += num
    print(value)
    return value

value = add_num(value, 3)
print(value)


