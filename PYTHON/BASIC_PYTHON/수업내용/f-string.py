import datetime

name = "Julie Yöön 소영 ★"
print(f"Hi! {name!r}")
print(f"Hi! {repr(name)}")

print(f"Hi! {name!s}")
print(f"Hi! {str(name)}")

print(f"Hi! {name!a}")
print(f"Hi! {ascii(name)}")

width = 10
precision = 3
c = 12.34567
print(f"{c : {width}.{precision}}")
today = datetime.datetime(year=2019, month=9, day=20)
print(f"{today: %B %d, %Y}")
a = {'a':100, 'b':200, 'c':300}
print(f"abc {a['c']} def")
a = 12
print(f"{a:#0X}")
newline = ord('\n')
print(f"newline: {newline}")
