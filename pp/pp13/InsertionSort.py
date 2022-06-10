def insertion_sort(values):

    '''[4]'''
    if (len(values) <= 1) :
        return
    for x in range(0, len(values)):
        for y in range(x, 0, -1):
            if (values[y - 1] > values[y]):
                values[y - 1], values[y] = values[y], values[y - 1]
            # print(values)
