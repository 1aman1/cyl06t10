#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        int N = nums.size();

        for (int i = 0; i < N; ++i)
        {
            while (nums[i] > 0 &&
                   nums[i] <= N &&
                   nums[i] != nums[nums[i] - 1])

                std::swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < N; ++i)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return N + 1;
    }
};

// Driver code
int main()
{
    Solution obj;
    std::vector<int> arr = {3, 4, -1, 1};

    int ans = obj.firstMissingPositive(arr);

    std::cout << ans;

    return 0;
}