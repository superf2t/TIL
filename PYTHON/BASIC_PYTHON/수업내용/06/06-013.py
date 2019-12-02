#06-013.py
import re

data = '''There is no mistaking
There is a real book
It is like falling in love
A true love'''
print(re.search(r'^There', data)) 
print(re.search(r'love$', data))
print('-------------------------------------------------')
print(re.search(r'^There', data, re.M))
print(re.search(r'love$', data, re.M))
print('-------------------------------------------------')
print(re.search(r'\AThere', data))
print(re.search(r'love\Z', data))
print('-------------------------------------------------')
print(re.search(r'\AThere', data, re.M))
print(re.search(r'love\Z', data, re.M))
print('-------------------------------------------------')

'''
print(re.findall(r'^There', data))
print(re.findall(r'^There', data, re.M))
print(re.findall(r'love$', data))
print(re.findall(r'love$', data, re.M))

print(re.findall(r'^It', data))
print(re.findall(r'^It', data, re.M))
'''
it = re.finditer(r'(^There) ([a-z]+)', data, re.M)

for x in it:
    print(x.group(), x.group(1), x.group(2))
    print(x.groups())
    for y in x.groups():
        print(y)

