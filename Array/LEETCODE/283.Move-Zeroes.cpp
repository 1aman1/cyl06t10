#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int last_non_zero = 0;

        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] != 0)
            {
                nums[last_non_zero] = nums[i];
                ++last_non_zero;
            }
        }
        for (; last_non_zero < size; ++last_non_zero)
            nums[last_non_zero] = 0;
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    Solution obj;
    obj.moveZeroes(nums);

    for (auto i : nums)
        cout << i << "\n";
    return 0;
}