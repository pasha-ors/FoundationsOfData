def daily_temperatures(nums):

    stack = []

    res = [0] * len(nums)

    for i in range(len(nums)):

        while stack and nums[i] > nums[stack[-1]]:

            index = stack.pop()

            res[index] = i - index

        stack.append(i)

    return res

