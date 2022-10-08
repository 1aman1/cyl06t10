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

            while (nums[i] >= 1 &&
                   nums[i] < N &&
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
    std::vector<int> arr = {1, 2, 0};

    int ans = firstMissingPositive(arr, 3);

    std::cout << ans;

    return 0;
}