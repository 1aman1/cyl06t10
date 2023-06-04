#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        int runningPrefix = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (runningPrefix == sum - nums[i] - runningPrefix)
                return i;
            runningPrefix += nums[i];
        }
        
        return -1;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    Solution obj;

    cout << obj.pivotIndex(nums);
    cout << obj.pivotIndex(nums);
    cout << obj.pivotIndex(nums);
    return 0;
}