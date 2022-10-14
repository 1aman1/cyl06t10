#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
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

class Solution2
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            const int mid = (right - left) / 2 + left;

            if (nums[mid] == target)
                return mid;

            if (target > nums[mid])
                left = mid + 1;
            else
                right = mid; // inclusively
        }

        return left;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    Solution obj;

    cout << obj.searchInsert(nums, 5) << "\n";
    cout << obj.searchInsert(nums, 2) << "\n";
    cout << obj.searchInsert(nums, 7) << "\n";
    return 0;
}