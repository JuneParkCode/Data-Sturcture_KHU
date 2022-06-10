def split(values, first, last):
    '''[7]'''
    splitValue = values[first]
    low = first + 1
    high = last
    while (low <= high):
        if (splitValue < values[low]): # 옮겨야 하는 경우
            while (low < high and splitValue <= values[high]):
                high -= 1
            # 끝났을 때 low == high or values[high] < splitValue
            if (splitValue > values[high]):
                values[high], values[low] = values[low], values[high]
            else:
                high -= 1
        low += 1
    values[first], values[high] = values[high], values[first]
    return high # pivot index

def quick_sort(values, first, last):
    '''[8]'''
    if (first < last) :
        pivot = split(values, first, last)
        quick_sort(values, first, pivot - 1)
        quick_sort(values, pivot + 1, last)

