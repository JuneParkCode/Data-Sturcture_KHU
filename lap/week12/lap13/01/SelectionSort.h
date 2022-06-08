#include "Student.h"

void SelectionSort(Student ary[], int numElems);
int MinIndex(Student ary[], int startIndex, int endIndex);

int MinIndex(Student ary[], int startIndex, int endIndex)
{
    int indexOfMin = startIndex;
    for (int index = startIndex + 1; index <= endIndex; index++)
        if (strcmp(ary[index].getName(), ary[indexOfMin].getName()) < 0)
            indexOfMin = index;
    return indexOfMin;
}

void SelectionSort(Student ary[], int numElems)
{
    int endIndex = numElems - 1;
    for (int current = 0; current < endIndex; ++current)
    {
        int minIndex = MinIndex(ary, current, endIndex);
        Swap(ary[current], ary[minIndex]);
    }
}
