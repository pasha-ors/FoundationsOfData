def sum_range(n):

    if n == 1:
        return 1

    return n + sum_range(n-1)

print(sum_range(5))