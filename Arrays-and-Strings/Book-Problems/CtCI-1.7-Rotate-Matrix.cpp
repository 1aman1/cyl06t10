#include <iostream>
#include <vector>
#include <algorithm>

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

bool rotateMatrix_2(std::vector<std::vector<int>> &grid)
{
    std::reverse(begin(grid), end(grid));

    for (int i = 0; i < grid.size(); i++)
        for (int j = i + 1; j < grid.size(); j++) // swaps upper triangle
            std::swap(grid[i][j], grid[j][i]);
}

bool rotateMatrix_1(std::vector<std::vector<int>> &matrix)
{
    if (matrix.empty() || matrix.at(0).size() != matrix.size())
    { // if not square
        return false;
    }

    int side = matrix.size();

    for (int layer = 0; layer < side / 2; ++layer)
    {
        int first = layer;
        int last = (side - 1) - layer;

        for (int i = first; i < last; ++i)
        {
            int offset = i - first;

            // store left most top element
            int keepTop = matrix[first][i];

            // left to top
            // bottom to left,
            // right to bottom
            // top to right
            // lastly, use copied top

            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = keepTop;
        }
    }
    return true;
}

int main()
{
    std::vector<std::vector<int>> matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    printMatrix(matrix);
    rotateMatrix_1(matrix);
    rotateMatrix_2(matrix);
    printMatrix(matrix);

    return 0;
}