#include <iostream>

class Solution
{
public:
    long uniquePaths(int m, int n)
    {
        long totalPossiblePaths = 1;
        for (int i = n; i < (m + n - 1); i++)
        {
            totalPossiblePaths *= i;
            totalPossiblePaths /= (i - n + 1);
        }
        
        return totalPossiblePaths;
    }
};
int main()
{
    Solution obj;
    std::cout << obj.uniquePaths(3, 2)
              << std::endl;

    return 0;
}