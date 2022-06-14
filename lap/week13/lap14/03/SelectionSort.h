#include <iostream>

template<class T>
void SwapT(T* &item1, T* &item2)
// Post: Contents of item1 and item2 have been swapped.
{
  T* tempItem;

  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}

template<class T>
void SelectionSortPointer(T *values[], int numValues)
{
    int min;
    T minVal;

    for (int i = 0; i < numValues - 1; ++i)
    {
        min = i;
        minVal = *(values[i]);
        for (int j = i; j < numValues; ++j)
        {
            if (minVal > *(values[j]))
            {
                min = j;
                minVal = *(values[min]);
            }
        }
        SwapT(values[min], values[i]);
    }
}