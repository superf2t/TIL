#01-005.py

name = 'Julie'
age = 42
f1=1.3456  
print('{}, {}'.format(name, age))
print('{0}, {1}'.format(name, age))
print('{{}}  {{{}}}'.format(name))
print('{:.4}-{:5.2}'.format(f1, f1))
print('{a} {b}'.format(b=10, a='X'))
print('{:>5}-{:0>5}'.format(12,34))
print('{:<5}-{:0^5}'.format(12,34))
print('{:,}'.format(123456789))
