
def reheap_down(elements, root, bottom):
    '''[2]'''
# BASE 1
    if (root >= bottom):
        return
# GET IDXS
    leftIdx = root * 2 + 1
    rightIdx = root * 2 + 2

# BASE 2
    if (leftIdx >= bottom):
        return
# GET LARGEST NUMBER OF LEFT TREE
    reheap_down(elements, leftIdx, bottom)
    if (elements[root] < elements[leftIdx]):
        elements[root], elements[leftIdx] = elements[leftIdx], elements[root]

# BASE 3
    if (rightIdx >= bottom):
        return
# GET LARGEST NUMBER OF RIGHT TREE
    reheap_down(elements, rightIdx, bottom)
    if (elements[root] < elements[rightIdx]):
        elements[root], elements[rightIdx] = elements[rightIdx], elements[root]

    return

def heap_sort(values, numValues):
    '''[3]'''
    for i in range(0, numValues):
    # HEAPIFY
        reheap_down(values, 0, numValues - i)
    # MOVE LARGEST NUMBER TO BACK
        values[0], values[numValues - i - 1] = values[numValues - i - 1], values[0]
