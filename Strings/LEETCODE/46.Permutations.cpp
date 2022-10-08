#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> result;

    void permuteUtil(std::vector<int> &nums, int left, int right)
    {
        if (left == right)
            result.push_back(nums);
            
        for (auto i = left; i <= right; ++i)
        {
            std::swap(nums[i], nums[left]);
            permuteUtil(nums, left + 1, right);
            std::swap(nums[i], nums[left]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        permuteUtil(nums, 0, nums.size() - 1);

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