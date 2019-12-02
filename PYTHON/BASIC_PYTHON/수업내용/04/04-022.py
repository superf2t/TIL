#04-022.py

my_str = 'Have a good day!'
my_bytes = b'Have a good day!'
s1 = my_bytes.decode()
b1 = bytes(my_str, encoding='utf-8')

b2 = my_str.encode()
print(type(s1), s1, sep='\n')
print(type(b1), b1, type(b2), b2, sep='\n')







