#04-016.py

msg1 = 'Hello'
msg2 ='    Nice to meet you!  '
msg3 ='www.willtek.com'
print ('*' + msg1.rjust(3) + '*')
print (msg1.rjust(10, '-'))
print ('*' + msg1.ljust(10) + '*')
print (msg2.ljust(10, '-'))
print ('*' + msg1.center(10) + '*')
print (msg1.center(10, '-'))
print ('*' + msg2.strip() + '*')
print ('*' + msg2.rstrip() + '*')
print ('*' + msg2.lstrip() + '*')
print(msg3.strip('womc'))
print(msg3.rstrip('womc'))
print(msg3.lstrip('womc'))
print('abcabcabc'.find('abc', 4, 9))
print('abcabcabc'.index('abc', 4, 9))

