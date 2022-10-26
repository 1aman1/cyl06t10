#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixToIndex{{0, -1}};
        int prefix = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            prefix += nums[i];

            if (k != 0)
                prefix %= k;

            if (prefixToIndex.count(prefix))
            {
                if (i - prefixToIndex[prefix] > 1)
                    return true;
            }
            else
                prefixToIndex[prefix] = i;
        }

        return false;
    }
};

int main()
{
    Solution obj;
    // vector<int> nums = {23, 2, 4, 6, 7};
    // int k = 6;
    vector<int> nums = {23, 2, 4, 6, 6};
    int k = 7;

    cout << boolalpha
         << obj.checkSubarraySum(nums, k)
         << "\n";

    return 0;
}