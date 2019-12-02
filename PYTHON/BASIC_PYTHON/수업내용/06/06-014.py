#06-014.py

import re

pattern = re.compile(r'([0-9]{3})(:|-| )(?:[0-9]{3,4})\2(?P<pnum>[0-9]{4})')
mc = re.search(pattern, '010-123-4567')
if mc :
    print('{}~{}에 {}존재'.format(mc.start(), mc.end(), mc.group()))
    for x in mc.groups():
        print(x)
    print(mc.group('pnum'))
    print(mc.group(0))  # 전체 (생략해도 같은 결과! )
    print(mc.group(1))  # 첫 번째 캡쳐본
    print( type(mc.groups()) )  # str
    print( type(mc.group()) )    # tuple
else:
    print('문자열에 패턴이 존재하지 않음')

