#include <iostream>
#include <random>
#include "UnsortedType.h"
int main(void)
{
    UnsortedType<int> t1;

    for (int i = 0; i < 10; ++i)
        t1.InsertItem(rand());

    t1.PrintList();
    t1.DoSort();
    t1.PrintList();
}