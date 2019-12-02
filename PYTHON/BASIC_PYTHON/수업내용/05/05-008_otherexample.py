class AccountLoan:
    
    baseRate = 0.05
    
    def __init__(self, rate, amount):
        self.rate = rate
        self.amount = amount
        
    def getInterest(self):
        myrate = AccountLoan.baseRate + self.rate
        return int(self.amount * myrate)
    
    @classmethod
    def changeRate(cls, baseRate):
        if baseRate > 0.1:
            print("plz check again")
        else:
            cls.baseRate = baseRate



print(AccountLoan.baseRate)

a = AccountLoan(0.03, 10000)
b = AccountLoan(0.02, 10000)

print(a.amount, a.baseRate, a.rate, a.getInterest())
print(b.amount, b.baseRate, b.rate, b.getInterest())

AccountLoan.changeRate(0.04)
##AccountLoan.baseRate = 0.04
## 왜 바로 접근해도 되는데 굳이 함수를 만들어서 위처럼 접근하는가?
## Ans: 위의 함수를 보면, 여러가지 statement가 들어가 있는데,
##          바로 접근을 해버리면 이상한 값을 대입하면 바로 바뀌기는 하지만
##          잘못된 값을 줘버려도 그냥 적용. 하지만 그것을 방지할 수 있음!

print(AccountLoan.baseRate)


print(a.amount, a.baseRate, a.rate, a.getInterest())
print(b.amount, b.baseRate, b.rate, b.getInterest())
