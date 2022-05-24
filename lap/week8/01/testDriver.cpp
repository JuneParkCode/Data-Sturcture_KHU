#include <iostream>
#include "UnsortedType.h"
/*
    return 0; 이 바로 실행되어 이하의 코드는 실행되지 않음.

*/
template <class ItemType>
ItemType SumSquares_a(NodeType<ItemType> *list)
{
    if (list == NULL)
        return 0;
    else
        return (list->info * list->info) + SumSquares_a(list->next);
};

/*
    Square의 합이 아닌 일반합
*/
template <class ItemType>
ItemType SumSquares_b(NodeType<ItemType> *list)
{
    int sum = 0;
    while (list != NULL)
    {
        sum = list->info * list->info + sum;
        list = list->next;
    }
    return sum;
};
/*
    ok
*/
template <class ItemType>
ItemType SumSquares_c(NodeType<ItemType> *list)
{
    if (list == NULL)
        return 0;
    else
        return list->info * list->info + SumSquares_c(list->next);
};
/*
    list == NULL일때 처리 불가능 이외는 OK -> 근데 사용자 실수를 따로 처리해야함?
*/
template <class ItemType>
ItemType SumSquares_d(NodeType<ItemType> *list)
{
    if (list->next == NULL)
        return list->info * list->info;
    else
        return list->info * list->info + SumSquares_d(list->next);
};
/*
    결과적으로 0 * 0 꼴이 될 것.
    -> c 형태로 고치는 것이 바람직하다.
*/
template <class ItemType>
ItemType SumSquares_e(NodeType<ItemType> *list)
{
    if (list == NULL)
        return 0;
    else
        return list->info * list->info + SumSquares_e(list->next);
}

// for test...
int main(void)
{
    UnsortedType<int> t1;
    int sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        t1.InsertItem(i);
        sum += i * i;
    }
    std::cout << "sum (recur) ";
    t1.PrintSumSquare();
    std::cout << "\nsum (iter) " << sum << std::endl;
    std::cout << "sum (a) " << SumSquares_a(t1.GetData()) << std::endl;
    std::cout << "sum (b) " << SumSquares_b(t1.GetData()) << std::endl;
    std::cout << "sum (c) " << SumSquares_c(t1.GetData()) << std::endl;
    std::cout << "sum (d) " << SumSquares_d(t1.GetData()) << std::endl;
    std::cout << "sum (e) " << SumSquares_e(t1.GetData()) << std::endl;
}