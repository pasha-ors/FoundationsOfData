def find_max(arr):

    if len(arr) == 1:
        return arr[0]
    
    max_of_rest = find_max(arr[1:])

    return arr[0] if arr[0] > max_of_rest else max_of_rest


print(find_max([1, 2, 3, 50]))
