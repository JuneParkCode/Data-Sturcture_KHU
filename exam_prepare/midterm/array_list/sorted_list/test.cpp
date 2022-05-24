#include "sorted_list.hpp"
#include <iostream>
#include <random>

int main(void)
{
    SortedList<int> lst;

    for (int i = 0; i <= 10; ++i)
    {
        lst.insertItem(rand() % 100);
    }
    for (int i = 0; i <=10; ++i)
    {
        int x;
        if(lst.getNextItem(x))
            std::cout << x << "\n";
    }
}