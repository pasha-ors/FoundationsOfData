def remove_duplicates(nums):

    slow = 0

    for fast in range(1, len(nums)):

        if nums[fast] != nums[slow]:
            
            slow += 1

            nums[slow] = nums[fast]

    return slow + 1 # length of list

data = [10, 10, 0, 20, 30, 40, 40]
print(f"Before: {data}")
print(f"After: {remove_duplicates(data)}")