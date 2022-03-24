//
//  C.cpp
//  lap03
//
//  Created by 박성준 on 2022/03/22.
//

#include <iostream>
#include <random>


int BinarySearch(int array[], int sizeOfArray,  int value)
{
    int first, mid, last;

    first = 0;
    last = sizeOfArray - 1;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (array[mid] < value)
            first = mid + 1;
        else if (array[mid] > value)
            last = mid - 1;
        else
            return (mid);
    }
    if (first == sizeOfArray)
        return (-1);
    return (first);
}


void    do_test(int testArr1[], int value, int size, int expected)
{
    int t_val = BinarySearch(testArr1, size, value);
    std::cout << t_val << std::endl;
    if (expected == t_val)
        std::cout << "OK" << std::endl;
    else
        std::cout << "FAILED" << " expected : " << expected << " res : " << t_val << std::endl;
}

int main(void)
{
    int testArr1[100];
    int randN = rand() % 100 + 1;
    int t_val;
    for (int i = 0; i < 100; ++i)
    {
        testArr1[i] = i * randN;
        std::cout << testArr1[i] << " ";
    }
    std::cout << std::endl;
     // case OK
    do_test(testArr1, testArr1[10], 100, 10);
    do_test(testArr1, testArr1[0], 100, 0);
    do_test(testArr1, testArr1[99], 100, 99);
    do_test(testArr1, testArr1[50], 100, 50);
    do_test(testArr1, testArr1[50] + 1, 100, 51);
    do_test(testArr1, -1, 100, 0);
    do_test(testArr1, testArr1[99] + 1, 100, 99);
    return (0);
}