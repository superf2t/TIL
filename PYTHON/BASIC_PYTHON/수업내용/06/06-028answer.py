#06-028answer.py

import re
def removeKor(msg):
    print(re.sub(r'[가-힣]+', '', msg))

removeKor('강아지12마리')
removeKor('11월 30일')
removeKor('2012년 1월 1일')
