#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        {
            vector<int> spiralSeq;

            // Corner cases
            if (matrix.size() == 0 /* depth check*/ || matrix[0].size() == 0 /* width check*/)
            {
                return spiralSeq;
            }

            int top = 0, bottom = matrix.size() - 1;
            int right = matrix[0].size() - 1, left = 0;

            int DIR; // direction switch

            while (top <= bottom && left <= right)
            {
                DIR = 0;
                if (DIR == 0)
                {
                    for (int i = left; i <= right; i++)
                    {
                        spiralSeq.push_back(matrix[top][i]);
                    }
                    top++;
                    if (top <= bottom)
                    {
                        DIR++;
                    }
                }
                if (DIR == 1)
                {
                    for (int i = top; i <= bottom; i++)
                    {
                        spiralSeq.push_back(matrix[i][right]);
                    }
                    right--;
                    if (left <= right)
                    {
                        DIR++;
                    }
                }
                if (DIR == 2)
                {
                    for (int i = right; i >= left; i--)
                    {
                        spiralSeq.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                    if (top <= bottom)
                    {
                        DIR++;
                    }
                }
                if (DIR == 3)
                {
                    for (int i = bottom; i >= top; i--)
                    {
                        spiralSeq.push_back(matrix[i][left]);
                    }
                    left++;
                    if (left <= right)
                    {
                        DIR++;
                    }
                }
            }
            return spiralSeq;
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {
                                                 4,
                                                 5,
                                                 6,
                                             },
                                  {7, 8, 9}};
    Solution obj;

    for (const auto &i : obj.spiralOrder(matrix))
        std::cout << i << " ";

    return 0;
}