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
        // std::cout << matrix.size() << " " << matrix.at(0).size();
        // 3 4

        // std::vector<std::vector<int>>::iterator rowItr;
        // std::vector<int>::iterator colItr;

        for (auto rowItr = matrix.begin(); rowItr != matrix.end(); ++rowItr)
        {
            // for (colItr = rowItr->begin(); colItr != rowItr->end(); ++colItr)

            // when the target is within range of the first row of elements
            if (rowItr->front() <= target && target <= rowItr->back())
            {
                return std::binary_search(rowItr->begin(), rowItr->end(), target);
            }

            // std::cout << " skipping \n";
            // else move to the next row for range check
            continue;
        }
        // value was not present
        // std::cout << " value was not present\n";
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