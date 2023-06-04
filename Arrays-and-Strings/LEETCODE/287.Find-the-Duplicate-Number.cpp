#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int findDuplicate(std::vector<int> &nums)
    {
        int slow_x, fast_2x;

        slow_x = fast_2x = 0;
        do
        {
            slow_x = nums[slow_x];
            fast_2x = nums[nums[fast_2x]];
        } while (slow_x != fast_2x);

        slow_x = 0;

        while (slow_x != fast_2x)
        {
            slow_x = nums[slow_x];
            fast_2x = nums[fast_2x];
        }

        return slow_x;
    }
};

int main()
{
    Solution obj;

    std::vector<int> nums = {1, 3, 4, 2, 2};

    std::cout << obj.findDuplicate(nums) << std::endl;

    return 0;
}