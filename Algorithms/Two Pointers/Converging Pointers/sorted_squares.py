def sorted_squares(arr): # array is sorted 

    n = len(arr)
    result = [0] * n
    left = 0
    right = n - 1
    pos = n - 1

    while(left <= right):
        left_sq = arr[left] ** 2
        right_sq = arr[right] ** 2

        if left_sq > right_sq:
            result[pos] = left_sq
            left += 1
        else:
            result[pos] = right_sq
            right -= 1

        pos -= 1

    return result


data = [-4, -1, 0, 3, 10]
print(f"Before:    {data}")
print(f"After: {sorted_squares(data.copy())}")


