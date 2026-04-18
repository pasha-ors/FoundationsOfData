def move_num(nums, num): 

    slow = 0
        
    for fast in range(len(nums)):
        if  nums[fast] != num:
            nums[slow], nums[fast] = nums[fast], nums[slow]

            slow += 1

    return nums


data = [10, 0, 20, 30, 0, 40]

print(f"Before: {data}")
print(f"After: {move_num(data, 0)}")
         