#02-011.py

def power(base, n):
    return (base) ** n

def power_base(base):
    def power_without_name(n):
        return power(base, n)
    return power_without_name

power_2 = power_base(2)
power_3 = power_base(3)
print(type(power_2), type(power_3))
print(id(power_2), id(power_3))
#print(id(power_2), id(power_3))
print(power_2(10))
print(power_3(3))

