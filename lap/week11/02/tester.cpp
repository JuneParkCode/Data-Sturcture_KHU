#include <iostream>
#include "PQType.h"

/*
 *
 * EX02
 *
 *  A
 *                 28
 *         27           19
 *      26    15       3  2
 *   25  24  5
 *  B : 예상 결과 x = 56, y = 42, z = 40
 *
 */

int main(int argc, char *argv[])
{
    PQType<int> pq(50);

    pq.Enqueue(56);
    pq.Enqueue(27);
    pq.Enqueue(42);
    pq.Enqueue(26);
    pq.Enqueue(15);
    pq.Enqueue(3);
    pq.Enqueue(19);
    pq.Enqueue(25);
    pq.Enqueue(24);
    pq.Enqueue(5);

    pq.Enqueue(28);
    pq.Enqueue(2);
    pq.Enqueue(40);

    const int SIZE = 3;
    int x;

    for (int i = 0; i < 3; ++i, std::cout << " ")
    {
        pq.Dequeue(x);
        std::cout << x;
    }
}
