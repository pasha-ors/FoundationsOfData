def reverse_array(array):

    left = 0
    right = len(array)-1

    while(left < right):
        array[left], array[right] = array[right], array[left]

        left += 1
        right -= 1

    return array

def reverse_array_xor(array): # only numbers

    left = 0
    right = len(array)-1

    while(left < right):
        array[left] ^= array[right]
        array[right] ^= array[left]
        array[left] ^= array[right]

        left += 1
        right -= 1

    return array


data = [10, 20, 30, 40, 50]
print(f"Before:    {data}")
print(f"After: {reverse_array(data.copy())}")
print(f"After Xor: {reverse_array_xor(data.copy())}")