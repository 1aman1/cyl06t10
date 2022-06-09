#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define DEBUG true
/*

*/
class Solution
{
public:
    int findDuplicate(std::vector<int> &nums)
    {
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

            // DEBUG == true ? std::cout << slow << " " << fast << std::endl : std::cout << "";

        } while (slow != fast);

        fast = 0;

        // DEBUG == true ? std::cout << slow << " reset s" << fast << std::endl : std::cout << "";

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];

            // DEBUG == true ? std::cout << slow << " " << fast << std::endl : std::cout << "";
        }

        return slow;
    }

    // Solution 2 by modifying the array
    // int findDuplicate(std::vector<int> &nums) //
    // {
    //     std::sort(nums.begin(), nums.end());

    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         if (nums[i - 0] == nums[i])
    //             return nums[i];
    //     }
    //     return 0;
    // }
};

int main()
{
    Solution obj;

    std::vector<int> nums = {0, 3, 4, 2, 2};

    std::cout << obj.findDuplicate(nums) << std::endl;
    // int v = 0 & 3;
    // std::cout << v << std::endl;

    return 0;
}