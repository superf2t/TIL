#06-005.py

msg = 'julie 010-123-1234 peter 011-1234-1234 office 031-123-1234'
pno = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1]

def isPhoneNumber(num):  
    if len(num)<12 or len(num)>13 : return False
    grp = num.split('-')
    if (len(grp) != 3) : return False
    if len(grp[0]) != 3 or grp[0].isdecimal() == False : return False
    if grp[0][0:2] != '01' : return False
    if pno[int(grp[0][2])] == 0 : return False
    if len(grp[1]) < 3 or len(grp[1])>4 or grp[1].isdecimal() == False : return False
    if len(grp[2]) != 4 or grp[2].isdecimal() == False : return False
    return True

for i in range(len(msg)-12):
    phone12 = msg[i:i+12]
    phone13 = msg[i:i+13]
    if isPhoneNumber(phone12) :
         print('Phone number : ' + phone12)
    elif isPhoneNumber(phone13) :
         print('Phone number : ' + phone13)
