
def bubble_sort(values):
    """[1]"""
    if (len(values) <= 1) :
        return
    for x in range(0, len(values) - 1):
        for y in range(0, len(values) - 1):
            if (values[y] > values[y + 1]):
                values[y], values[y + 1] = values[y + 1], values[y]


