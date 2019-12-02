#01-014.py

num = 0b_0011_0011_1100_1100_0101_0101
setbit = 3
clearbit = 2
print(bin(num))
print(bin(num | 1 << setbit))
print(bin(num & ~(1 << clearbit)))

