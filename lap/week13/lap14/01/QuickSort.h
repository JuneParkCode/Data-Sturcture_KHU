#include <iostream>

template <class ItemType>
void SWAP(ItemType& item1, ItemType& item2)
// Post: Contents of item1 and item2 have been swapped.
{
  ItemType tempItem;

  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}

template <class ItemType>
int split(ItemType arr[], int first, int last)
{
    const int originFist = first;
    ItemType pivotValue = arr[first];

    while (first <= last)
    {
        // first item > pivot  -> swap (first, last)
        // last item < pivot -> swap (first, last)
        while (first <= last && arr[first] <= pivotValue)
            ++first;
        while (first <= last && arr[last] >= pivotValue)
            --last;
        if (first < last)
        {
            SWAP(arr[first], arr[last]);
            ++first;
            --last;
        }
    }
    SWAP(arr[originFist], arr[last]);
    return (last); // next pivot point
}

template <class ItemType>
void QuickSort(ItemType arr[], int first, int last)
{
    if (first < last)
    {
        int pivot = split(arr, first, last);
        QuickSort(arr, first, pivot - 1);
        QuickSort(arr, pivot + 1, last);
    }
}