#include <iostream>
#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int track_greater_number = right;

        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target)
            {
                return mid;
            }

            else if (target < nums[mid])
            {
                right = mid - 1;
                track_greater_number = mid;
            }
            else
                left = mid + 1;
        }

        while (track_greater_number >= 0 &&
               nums[track_greater_number] > target)
        {
            --track_greater_number;
        }

        return 1 + track_greater_number;
    }
};

int main()
{
    std::vector<int> nums = {1, 3, 5, 6};
    Solution obj;
    std::cout << obj.searchInsert(nums, 5);
    std::cout << obj.searchInsert(nums, 2);
    std::cout << obj.searchInsert(nums, 7);
    return 0;
}