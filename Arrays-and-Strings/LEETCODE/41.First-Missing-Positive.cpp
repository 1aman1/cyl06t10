#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        int size = nums.size();

        for (int i = 0; i < size; ++i)
        {
            while (nums[i] > 0 &&
                   nums[i] < size &&
                   nums[i] != nums[nums[i] - 1])

                std::swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return size + 1;
    }
};

// Driver code
int main()
{
    Solution obj;
    std::vector<int> arr = {1, 3, 6, 4, 1, 2};

    int ans = obj.firstMissingPositive(arr);

    std::cout << ans;

    return 0;
}