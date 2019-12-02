#03-003.py

def getEvenOdd(num):
    return print(num, 'is', 'Odd' if num % 2 else 'Even')

def getOddEven(num):
    return print(num, 'is', (num % 2) and 'Odd' or 'Even')

getEvenOdd(10)
getEvenOdd(11)
getOddEven(10)
getOddEven(11)

