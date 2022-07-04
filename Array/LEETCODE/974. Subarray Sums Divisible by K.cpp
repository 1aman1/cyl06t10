#include <iostream>
#include <vector>

class Solution
{
public:
    int subarraysDivByK(std::vector<int> &nums, int k)
    {
        std::vector<int> kMod(k, 0);

        int cumulativeSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            cumulativeSum += nums[i];
            int tmp;
            tmp = cumulativeSum % k;
            // tmp = ((cumulativeSum % k) + k) % k;

            ++kMod[tmp];
        }

        int count = 0;
        for (int i = 0; i < k; ++i)
        {
            if (kMod[i] > 1)
            {
                count += (kMod[i] * (kMod[i] - 1)) / 2;
            }
        }
        count += kMod[0];

        return count;
    }
};

int main()
{

    std::vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    Solution obj;
    std::cout << obj.subarraysDivByK(nums, k);

    return 0;
}