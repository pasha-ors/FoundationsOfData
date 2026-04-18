def two_sum(arr, target): # arr is sorted

    left = 0
    right = len(arr) - 1

    while(left < right):

        sum = arr[left] + arr[right]

        if sum == target:
            return (left, right)
        
        if sum > target:
            right -= 1

        if sum < target:
            left += 1

    return (-1, -1)

data = [10, 20, 30, 40, 50]
target = 70
print(f"Array: {data}, Target: {target}")
print(f"Result: {two_sum(data, target)}")