#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define INTMIN -99999

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::vector<int> result;

        for (long unsigned int i = 0; i < nums.size(); ++i)
        { // mark frequency for each
            ++result[nums[i]];
        }

        for (int i = 0; i < k; ++i)
        {
            // itr to ptr
            auto maxItr = std::max_element(result.begin(), result.end());

            // item itself
            int item = std::distance(maxItr, result.begin());
            std::cout << " item: " << item;
            result.push_back(item);
            *maxItr = INTMIN;
        }

        return result;
    }
};

int main()
{
    std::vector<int> nums = {1, 1, 1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution obj;
    std::vector<int> result = obj.topKFrequent(nums, k);

    for (const auto &itr : result)
    {
        std::cout << itr << std::endl;
    }

    return 0;
}
