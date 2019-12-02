#04-034.py

even_nums = [2, 4, 6, 8, 10, 12, 14, 16, 18]
r = filter(lambda x: x % 6 !=0, even_nums)
print(type(r), list(r))

names = [ 'Happy', 'Joy', 'Merry', 'Minky', 'Adam' ]
r = filter(lambda x : x.startswith('M'), names)
print(type(r), list(r))
