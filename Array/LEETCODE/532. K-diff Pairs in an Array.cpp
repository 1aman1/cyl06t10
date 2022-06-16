#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int findPairs(std::vector<int> &nums, int k)
    {
        int countPairs = 0;
        int prev_k_sum;

        std::sort(nums.begin(), nums.end());

        for (auto itr = nums.begin(); itr != nums.end(); ++itr)
        {
            int curr_sum_k = (*itr) + k;

            if (prev_k_sum == curr_sum_k) // skip duplicate pair
                continue;

            prev_k_sum = curr_sum_k;
            if (std::binary_search(itr + 1, nums.end(), curr_sum_k))
            {
                ++countPairs;
            }
        }

        return countPairs;
    }
};

int main()
{
    std::vector<int> v = {3, 1, 4, 1, 5};
    // std::vector<int> v = {1, 1, 1, 1, 1};

    Solution obj;
    int k = 2;
    std::cout << obj.findPairs(v, k);

    return 0;
}