#04-029.py

nums='1237894673683038478236749192738623234234'

if 1:
    cnt = {}
    for num in nums:
        cnt.setdefault(num, 0)
        cnt[num] += 1
    
else:
    # 위에서 for문을 돌려서 만든 cnt를 Counter 메소드를 통해 한 번에 만들 수도 있음!
    from collections import Counter
    cnt = Counter(nums)

    
print(cnt)



# 1. 등장 횟수(빈도 수)를 기준으로 오름차순으로 정렬 가능!?!?
# 어렵고도 신기함..!
if 0:
    # 1-1)
    cnt_tmp = { i:cnt[i] for i in sorted(cnt, key = lambda x : cnt[x]) }
    print(cnt_tmp)
    
else:
    
    # 1-2)
    cnt_tmp = { i:j for i, j in sorted(cnt.items(), key = lambda x : x[1]) }
    print(cnt_tmp)


# 2. key 0 ~ 9까지의 ...
##cnt_tmp = dict.fromkeys("0123456789", 0)
cnt_tmp = { k : cnt.get(k, 0) for k in "0123456789"}

##for i in cnt_tmp:
##    cnt_tmp[i] = cnt.get(i, 0)
print(cnt_tmp)






##from collections import Counter
##X = Counter(nums)
##y = [ (x, y) for x, y in X.items() ]
##y.sort()
##X = { x:y for x,  y in y }
##print(X)
