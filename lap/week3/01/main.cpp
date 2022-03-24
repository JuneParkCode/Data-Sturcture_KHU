//
//  main.cpp
//  lap03
//
//  Created by 박성준 on 2022/03/22.
//

#include <iostream>
#include "header/ItemType.h"
#include "header/sorted.h"

//  BIG O(N)
void  MergeList(SortedType list1, SortedType list2, SortedType& result)
{
    const int   len_l1 = list1.LengthIs();
    const int   len_l2 = list2.LengthIs();
    ItemType    item_1;
    ItemType    item_2;
    int         idx_l1;
    int         idx_l2;

    list1.ResetList();
    list2.ResetList();
    list1.GetNextItem(item_1);
    list2.GetNextItem(item_2);
    idx_l1 = 0;
    idx_l2 = 0;
    while (len_l1 != idx_l1 && len_l2 != idx_l2)
    {
        switch (item_1.ComparedTo(item_2))
        {
            case LESS:
                result.InsertItem(item_1);
                if (++idx_l1 < len_l1)
                    list1.GetNextItem(item_1);
                break;
            case GREATER:
                result.InsertItem(item_2);
                if (++idx_l2 < len_l2)
                    list2.GetNextItem(item_2);
                break;
            case EQUAL:
                break;
        }
    }
    while (len_l1 != idx_l1)
    {
        result.InsertItem(item_1);
        if (++idx_l1 < len_l1)
            list1.GetNextItem(item_1);
    }
    while (len_l2 != idx_l2)
    {
        result.InsertItem(item_2);
        if (++idx_l2 < len_l2)
            list2.GetNextItem(item_2);
    }
}

int main(void) {
    SortedType  l1;
    SortedType  l2;
    SortedType  result;
    ItemType    i1, i2;
    for (int i = 0; i < 2; ++i)
    {
        i1.Initialize(i * 2);
        i2.Initialize(i * 2 - 1);
        l1.InsertItem(i1);
        l2.InsertItem(i2);
    }

    std::cout << "\nL1" << std::endl;
    l1.ResetList();
    for (int i = 0; i < 2; ++i)
    {
        l1.GetNextItem(i1);
        i1.Print(std::cout);
    }
    std::cout << "\nL2" << std::endl;
    l2.ResetList();
    for (int i = 0; i < 2; ++i)
    {
        l2.GetNextItem(i2);
        i2.Print(std::cout);
    }
    MergeList(l1, l2, result);
    std::cout << "\nResult" << std::endl;
    result.ResetList();
    for (int i = 0; i < result.LengthIs(); ++i)
    {
        result.GetNextItem(i1);
        i1.Print(std::cout);
    }
    return (0);
}
