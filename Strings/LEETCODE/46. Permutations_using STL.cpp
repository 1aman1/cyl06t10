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

int main()
{
    std::vector<int> nums = {1, 2, 3};
    Solution obj;
    std::vector<std::vector<int>> result = obj.permute(nums);
    for (auto row = result.begin(); row != result.end(); ++row)
    {
        for (auto col = row->begin(); col != row->end(); ++col)
        {
            std::cout << *col << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}