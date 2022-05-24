#include <iostream>
#include <memory.h>

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
int mat[MAX_ROWS][MAX_COLS];

int NumPaths_B(int row, int col, int n)
{
    int value;

    if (mat[row][col] == -1)
        mat[row][col] = NumPaths_B(row + 1, col, n) + NumPaths_B(row, col + 1, n);
    if (row == n || col == n)
        return (1);
    else
        return mat[row][col];
}

int main(int argc, char *argv[])
{
    int n;
    if (argc != 2)
        n = 10;
    else
        n = atoi(argv[1]);

    memset(mat, -1, MAX_ROWS * MAX_COLS * sizeof(int));
    std::cout
        << NumPaths_B(1, 1, n) << std::endl;
}