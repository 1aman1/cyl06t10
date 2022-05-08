#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MIN -99999

class Solution
{
public:
    // O(n)
    int maxSubArray(std::vector<int> &nums)
    {
        // max of ( current, current + prevMaximum)
        int prevMaximum = 0;
        int maximumAbsolute = INT_MIN;

        for (int i = 0; i < nums.size(); ++i)
        {
            // std::cout << nums[i] << " ";
            prevMaximum = std::max(nums[i], prevMaximum + nums[i]);
            // std::cout << prevMaximum << " " << maximumAbsolute << std::endl;
            if (maximumAbsolute < prevMaximum)
                maximumAbsolute = prevMaximum;
        }

        // std::cout << prevMaximum << " " << maximumAbsolute;
        return maximumAbsolute;
    }
};

int main()
{
    Solution obj;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // kadane's algo helps here
    std::cout << obj.maxSubArray(nums) << std::endl;

    return 0;
}