def max_area(arr):

    left = 0
    right = len(arr) - 1

    max_area = 0

    while(left < right):

        area = min(arr[left], arr[right]) * (right - left)

        max_area = max(area, max_area)

        if arr[right] > arr[left]:
            left += 1
        else:
            right -=1

    return max_area


data = [10, 80, 30, 40, 50, 10]
print(f"Array: {data}")
print(f"Max_area: {max_area(data)}")