from BubbleSort import *
from SelectionSort import *
from InsertionSort import *
from MergeSort import *
from QuickSort import *
from HeapSort import *
from ShortBubble import *

if __name__ == '__main__':
    arr = [8,5,4,6,2,10,3,99,13,51,345,21,51,0]
    bubble_sort(arr)
    print("BUBBLE",arr)

    arr = [8,5,4,6,2,10,3,99,13,51,345,21,51,0]
    selection_sort(arr)
    print("SELECTION", arr)

    arr = [8,5,4,6,2,10,3,99,13,51,345,21,51,0]
    insertion_sort(arr)
    print("INSERTION", arr)

    arr = [8,5,4,6,2,10,3,99,13,51,345,21,51,0]
    merge_sort(arr, 0, len(arr)-1)
    print("MERGE",arr)

    arr = [8,5,4,6,2,10,3,99,13,51,345,21,51,0]
    quick_sort(arr, 0, len(arr)-1)
    print("QUICK", arr)

    arr = [8,5,4,6,2,10,3,99,13,51,345,21,51,0]
    heap_sort(arr, len(arr))
    print("HEAP", arr)

    arr = [8,5,4,6,2,10,3,99,13,51,345,21,51,0]
    short_bubble(arr, len(arr))
    print("SHORT BUBBLE",arr)
