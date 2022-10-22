#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    // O(n)
    // Space(n)
    // 26ms
    int majorityElement(std::vector<int> &nums)
    {
        std::unordered_map<int, int> frequency;

        int maxCount = 0;
        int majorityCount = nums.size() / 2;

        for (const auto &values : nums)
        {
            if (++frequency[values] > majorityCount)
                return values;
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    std::vector<int> nums = {1, 1, 1, 1, 1, 1, 2, 2, 2, 10};

    std::cout << obj.majorityElement(nums) << std::endl;

    return 0;
}