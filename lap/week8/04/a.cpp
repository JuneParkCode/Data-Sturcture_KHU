#include <iostream>

int NumPaths_A(int row, int col, int n)
{
    if (row == n || col == n)
        return (1);
    else
        return (NumPaths_A(row + 1, col, n) + NumPaths_A(row, col + 1, n));
}

int main(int argc, char *argv[])
{
    int n;
    if (argc != 2)
        n = 10;
    else
        n = atoi(argv[1]);

    std::cout << NumPaths_A(1, 1, n) << std::endl;
}