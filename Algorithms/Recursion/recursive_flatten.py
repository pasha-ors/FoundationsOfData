def recursive_flatten(data):

    # [1, [2, [3, 4]]] --> [1, 2, 3, 4]
    
    result = []
    

    for item in data:

        if isinstance(item, list):

            result.extend(recursive_flatten(item))

        else:

            result.append(item)

    return result


print(recursive_flatten([1, [2, [3, 4]]]))