def count_files(directory):

    total = 0

    for i in directory.list_contents():

        if i.is_directory():

            total += count_files(i)

        else:

            total += 1

    return total