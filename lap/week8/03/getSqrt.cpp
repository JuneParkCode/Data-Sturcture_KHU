#include <cmath>
#include <iostream>
#define SQUARE(X) X *X

float SqrtRoot_recursion(int n, float approx, float tol)
{
    if (abs(SQUARE(approx) - n) <= tol)
        return (approx);
    else
        return SqrtRoot_recursion(n, (SQUARE(approx) + n) / (2 * approx), tol);
}

float SqrtRoot_non_recursion(int n, float approx, float tol)
{
    while (abs(SQUARE(approx) - n) > tol)
    {
        approx = (SQUARE(approx) + n) / (2 * approx);
    }
    return (approx);
}

int main(int argc, char *argv[])
{
    int n;
    float approx, tol;

    if (argc != 2)
        n = 2;
    else
        n = atoi(argv[1]);
    approx = n / 2;
    tol = 0.01;
    std::cout << SqrtRoot_recursion(n, approx, tol) << std::endl;
    std::cout << SqrtRoot_non_recursion(n, approx, tol) << std::endl;
    return (0);
}