#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MIN -99999

// this is known as kadane's algorithm
class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int local_maximum = 0;
        int maximum = INT_MIN;

        for (const auto &i : nums)
        {
            local_maximum = std::max(i, i + local_maximum);
            if (maximum < local_maximum)
                maximum = local_maximum;
        }
        return maximum;
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

// credits : kadane