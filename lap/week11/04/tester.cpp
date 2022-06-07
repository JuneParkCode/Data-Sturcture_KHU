#include <iostream>
#include "PSType.h"

int main(void)
{
    PSType<int> stk;

    int x;

    for (int i = 0; i < 11; ++i)
    {
        stk.Push(i);
    }

    while (!stk.IsEmpty())
    {
        stk.Pop(x);
        std::cout << x << std::endl;
    }
}