#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    const int row = matrix.size();
    const int col = matrix[0].size();
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    for (int j = 0; j < col; ++j)
        if (matrix[0][j] == 0)
        {
            firstRowHasZero = true;
            break;
        }

    for (int i = 0; i < row; ++i)
        if (matrix[i][0] == 0)
        {
            firstColHasZero = true;
            break;
        }

    for (int i = 1; i < row; ++i)
        for (int j = 1; j < col; ++j)
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }

    for (int i = 1; i < row; ++i)
        for (int j = 1; j < col; ++j)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    if (firstRowHasZero)
        for (int j = 0; j < col; ++j)
            matrix[0][j] = 0;

    if (firstColHasZero)
        for (int i = 0; i < row; ++i)
            matrix[i][0] = 0;
}

void printMatrix(const std::vector<std::vector<int>> &matrix)
{

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.at(0).size(); ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::vector<int>> matrix{
        {1, 2, 3, 4},
        {5, 6, 0, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    printMatrix(matrix);
    setZeroes(matrix);
    printMatrix(matrix);

    return 0;
}