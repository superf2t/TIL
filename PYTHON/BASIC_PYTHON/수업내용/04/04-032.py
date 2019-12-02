#04-032.py

odd = [ 1, 3, 5, 7, 9, 11, 13 ]
m = map(lambda x : x * x, odd)  # map은 iterator!!!
next(m)
next(m)         # iterator의 특징!!!!
print(list(m))                # list(  ) 안에 넣어줌으로써 iterable로 만들어줌!
print(list(m))                # next하면 다시 돌아갈 수 없음. 이미 다 끝났기 때문에 더이상 읽어올 수 없었던 것!

student = 'Julie | 010-123-456 | 42 | F'
print(student.split('|'))
m = map(str.strip, student.split('|'))
print(list(m))
