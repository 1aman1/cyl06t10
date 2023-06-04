#include <iostream>
#include <vector>
#include <algorithm>

/*
vector of R*C size

Big O( R * logC )
*/

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        for (auto IRow = matrix.begin(); IRow != matrix.end(); ++IRow)
        {
            if (IRow->front() <= target && target <= IRow->back())
            {
                return std::binary_search(IRow->begin(), IRow->end(), target);
            }

            continue;
        }
        return false;
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 3, 5, 7},
                                            {10, 11, 16, 20},
                                            {23, 30, 34, 60}};

    Solution obj;

    std::cout << std::boolalpha
              << obj.searchMatrix(matrix, 160)
              << std::endl;

    return 0;
}