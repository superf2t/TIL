#06-001.py

def isspecial(ch):
    return ch in '!@#$%^&*()'

def check(pw):
    if len(pw) < 10  : return False
    check = [0] * 4
    for ch in pw:
        if ch.islower() : check[0] = 1
        if ch.isupper() : check[1] = 1
        if ch.isdecimal() : check[2] = 1
        if isspecial(ch) : check[3] = 1
        if 0 not in check : return True
    return False

print(check('asbdJKL12**'))
print(check('123jkKL*'))
print(check('ajkdk123kjKL'))
print(check('ABC123*^5D'))
