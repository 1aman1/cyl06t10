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