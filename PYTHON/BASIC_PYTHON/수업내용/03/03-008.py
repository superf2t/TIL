#03-008.py

## a는 tuple로 Container임!! => Container은 iterable!!!
a = (1, 2, 3)
## interable은 iter() 메소드의 인자로 넘어감으로써, iter()를 통해서 iterator 리턴!!
b = iter(a)
print(next(b))
print(next(b))
print(next(b))

## 요소가 3개밖에 없으므로 StopIteration Exception(?)뜸!!
print(next(b))
