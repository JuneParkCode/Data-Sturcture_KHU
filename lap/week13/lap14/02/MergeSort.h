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
void Merge(ItemType arr[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
    const int ARR_SIZE = rightLast - leftFirst + 1;
    ItemType tmp[ARR_SIZE];
    int idx = 0;
    int idxLeft = leftFirst;
    int idxRight = rightFirst;
    while (idxLeft <= leftLast || idxRight <= rightLast)
    {
        if (idxLeft > leftLast)
        {
            while (idxRight <= rightLast)
                tmp[idx++] = arr[idxRight++];
        }
        else if (idxRight > rightLast)
        {
            while (idxLeft<= leftLast)
                tmp[idx++] = arr[idxLeft++];
        }
        else
        {
            ItemType &leftItem = arr[idxLeft];
            ItemType &rightItem = arr[idxRight];
            if (leftItem < rightItem)
            {
                tmp[idx++] = arr[idxLeft++];
            }
            else
            {
                tmp[idx++] = arr[idxRight++];
            }
        }
    }
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        arr[leftFirst + i] = tmp[i];
    }
}


template <class ItemType>
void MergeSort(ItemType arr[], int first, int last)
{
    if (first < last)
    {
        const int mid = (first + last) / 2;
        MergeSort(arr, first, mid);
        MergeSort(arr, mid + 1, last);
        Merge(arr, first, mid, mid + 1, last);
    }
}