def max_sum_subarray(nums, k):

    left = 0
    right = k
    current_sum = 0

    for i in range(k):
        current_sum += nums[i]

    max_sum = current_sum

    while(right < len(nums)-1):

        sum = current_sum - nums[left] + nums[right]

        if sum > max_sum:
            max_sum = sum

        left += 1
        right += 1


    return max_sum 

        