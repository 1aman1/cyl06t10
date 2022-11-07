#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        result.push_back(nums);
        sort(nums.begin(), nums.end());

        while (std::next_permutation(nums.begin(), nums.end()))
        {
            result.push_back(nums);
        }

        return result;
    }
};

void print(const std::vector<std::vector<int>> &result)
{
    for (auto row : result)
    {
        for (auto col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<int> nums = {1, 2, 3};
    Solution obj;

    std::vector<std::vector<int>> result = obj.permute(nums);

    print(result);

    return 0;
}