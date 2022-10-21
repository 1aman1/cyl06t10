#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int result;
        int count = 0;

        for (const auto &digit : nums)
        {
            if (!count)
                result = digit;

            count += (digit == result ? 1 : -1);
        }

        return result;
    }
};

int main()
{
    Solution obj;

    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    std::cout << obj.majorityElement(nums) << std::endl;

    return 0;
}