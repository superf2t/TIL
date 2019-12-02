#04-006.py

nums = [1, 2, 3]
print (id(nums), nums)
nums = [10, 20, 30]
print (id(nums), nums)

nums = [1, 2, 3]
print (id(nums), nums)
del nums[2]
del nums[1]
del nums[0]
nums.append(10)
nums.append(20)
nums.append(30)
print (id(nums), nums)

