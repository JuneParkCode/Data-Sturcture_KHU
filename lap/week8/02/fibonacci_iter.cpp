#include <iostream>
#include <ctime>

/**
 * fibonacci_iter 가 fibonacci_recur 보다 빠르다.
 * memorization을 이용하여 동일하게 구현한다고 하더라도 함수를 따로 생성하는 시간이 소요되기 때문.
 */

unsigned long long fibonacci_iter(unsigned long long n)
{
    const unsigned long long ARR_SIZE = n;
    unsigned long long res = 0;
    unsigned long long arr[ARR_SIZE];

    if (n <= 1)
        return (1);
    arr[0] = arr[1] = 1;
    for (unsigned long long i = 2; i <= n; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return (arr[n]);
}

unsigned long long fibonacci_recur(unsigned long long n)
{
    switch (n)
    {
    case 0:
    case 1:
        return 1;
    default:
        return (fibonacci_recur(n - 1) + fibonacci_recur(n - 2));
    }
}

int main(int argc, char *argv[])
{
    unsigned long long n;
    clock_t start, end;
    if (argc == 2)
    {
        n = atoi(argv[1]);
    }
    else
    {
        n = 40;
    }
    std::cout << "n = " << n << std::endl;
    start = clock();
    std::cout << "iter : " << fibonacci_iter(n) << std::endl;
    end = clock();
    std::cout << (double)(end - start) << std::endl;

    start = clock();
    std::cout << "recur :" << fibonacci_recur(n) << std::endl;
    end = clock();
    std::cout << (double)(end - start) << std::endl;

    return (0);
}