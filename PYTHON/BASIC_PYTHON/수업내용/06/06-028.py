#06-028.py

import re
def removeKor(msg):
   ret = re.sub(r'[가-힣]+', '', msg)
   print(ret)

removeKor('강아지12마리')
removeKor('11월 30일')
removeKor('2012년 1월 1일')
