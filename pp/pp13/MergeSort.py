def merge_sort(values, first, last):
    '''[5]'''
    if (first < 0 or first >= last):
        return
    leftFirst = first
    leftLast = first + (last - first) // 2
    rightFirst = leftLast + 1
    rightLast = last
    merge_sort(values, leftFirst, leftLast)
    merge_sort(values, rightFirst, rightLast)
    merge(values, leftFirst, leftLast, rightFirst,rightLast)

def merge(values, leftFirst, leftLast, rightFirst, rightLast):
    '''[6]'''
    lst = []
    valueIdx = leftFirst
    leftIdx = leftFirst
    rightIdx = rightFirst
    while (valueIdx <= rightLast):
        if (leftIdx <= leftLast and rightIdx <= rightLast):
            if (values[leftIdx] < values[rightIdx]):
                lst.append(values[leftIdx])
                leftIdx += 1
            else:
                lst.append(values[rightIdx])
                rightIdx += 1
        else:
            if (leftIdx > leftLast):
                lst.append(values[rightIdx])
                rightIdx += 1
            else:
                lst.append(values[leftIdx])
                leftIdx += 1
        valueIdx += 1
    idx = 0
    for i in range(leftFirst, rightLast + 1):
        values[i] = lst[idx]
        idx += 1

