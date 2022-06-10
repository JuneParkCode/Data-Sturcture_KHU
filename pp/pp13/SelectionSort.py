
def selection_sort(values):
    '''[9]'''
    if (len(values) <= 1) :
        return
    for x in range(0, len(values)):
        minValue = values[x]
        idxOfMinValue = x
        for y in range(x, len(values)):
            if (minValue >= values[y]):
                minValue = values[y]
                idxOfMinValue = y
        values[x], values[idxOfMinValue] = values[idxOfMinValue], values[x]

